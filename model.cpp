// model.cpp
#include "model.h"

Model::Model(QWidget *parent)
    : QWidget(parent)
    , world(nullptr)
    , scene()
    , collisionObjects()
{
    // Define the gravity vector.
    b2Vec2 gravity(0.0f, 200.0);

    // Construct a world object, which will hold and simulate the rigid bodies.
    world = new b2World(gravity);

    // player
    player = new Player(QPoint(0, 0), world);

    // createCollisionObject(QPoint(0, 100), QPoint(20, 100), 20);
    createCollisionObject(0, 440, 640, 40);

    // Connect the world timer to the worldStep() function
    connect(&worldTimer, &QTimer::timeout, this, &Model::worldStep);
    worldTimer.start(16); // 60 FPS
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
    Wall newWall(x, y, width, height, world);
    collisionObjects.push_back(newWall);
}


void Model::worldStep()
{
    if (world) {
        player->step();
        world->Step(1.0f / 60.0f, 8, 3);
        renderScene();
    }
}

void Model::renderScene() {
    QPixmap pixmap(width(), height());
    pixmap.fill(Qt::white);
    QPainter painter(&pixmap);

    QTransform transform;
    transform.scale(1.0, 1.0);
    // transform.translate(0.0, -64.0);
    painter.setTransform(transform);

    painter.setPen(Qt::NoPen);

    painter.setBrush(Qt::blue);
    b2Vec2 playerPosition = player->getTopLeft();
    painter.drawRect(playerPosition.x, playerPosition.y, player->width, player->height);
    // Render the walls
    painter.setBrush(Qt::red);
    for (const Wall& wall : collisionObjects) {
        painter.drawRect(wall.x, wall.y, wall.width, wall.height);
    }

    emit renderSceneOnView(pixmap);
}

void Model::onPlayerMoveState(Player::Movement state) {
    player->setMoveState(state);
}
