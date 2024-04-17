// model.cpp
#include "model.h"
#include "contactlistener.h"

Model::Model(QWidget *parent)
    : QWidget(parent)
    , world(nullptr)
    , worldContact(new ContactListener())
    , collisionObjects()
    , scene(width(), height())
    , painter(&scene)
    , elapsedTimer()
{
    b2Vec2 gravity(0.0f, -10.0);
    world = new b2World(gravity);
    world->SetContactListener(worldContact);

    worldState = { world, worldContact };

    // player
    player = new Player(QPoint(0, 0), &worldState);

    // createCollisionObject(QPoint(0, 100), QPoint(20, 100), 20);
    createCollisionObject(0., -50., 50., 5.);

    connect(&worldTimer, &QTimer::timeout, this, &Model::worldStep);
    worldTimer.start();
    elapsedTimer.start();
}

Model::~Model()
{
    delete world;
}

// void Model::createCollisionObject(QPoint p1, QPoint p2, int width)
// {
//     Wall newWall(p1, p2, width, world);
//     collisionObjects.push_back(newWall);
// }

void Model::createCollisionObject(int x, int y, int width, int height)
{
    Wall newWall(x, y, width, height, &worldState);
    collisionObjects.push_back(newWall);
}


void Model::worldStep()
{
    if (!world) {
        return;
    }

    qint64 currentTime = elapsedTimer.nsecsElapsed();
    qint64 elapsedTime = currentTime - lastFrameTime;

    if (elapsedTime >= FRAME_TIME_TARGET) {
        lastFrameTime = currentTime;

        player->step();
        world->Step(1.0f / 60.0f, 8, 3);

        qreal frameRate = 1e9 / static_cast<qreal>(elapsedTime);
        int roundedFrameRate = qRound(frameRate);
        // qDebug() << "Frame Rate:" << roundedFrameRate << "FPS";
    }

    renderScene();
}

void Model::renderScene() {
    scene.fill(Qt::white);

    painter.setPen(Qt::NoPen);

    painter.setBrush(Qt::blue);
    b2Vec2 playerPosition = SCALE_FACTOR * player->getTopLeft();
    painter.drawRect(playerPosition.x, playerPosition.y, player->width * SCALE_FACTOR, player->height * SCALE_FACTOR);
    // Render the walls
    painter.setBrush(Qt::red);
    for (const Wall& wall : collisionObjects) {
        painter.drawRect(wall.x * SCALE_FACTOR, wall.y * SCALE_FACTOR, wall.width * SCALE_FACTOR, wall.height * SCALE_FACTOR);
    }

    QTransform transform;
    transform.scale(1.0, -1.0);
    painter.setTransform(transform);

    emit renderSceneOnView(scene);
}

void Model::onPlayerMoveState(Player::Movement state, bool isDown) {
    player->setMoveState(state, isDown);
}
