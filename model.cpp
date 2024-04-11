// model.cpp
#include "model.h"

Model::Model(QWidget *parent)
    : QWidget(parent)
    , world(nullptr)
    , scene()
    , collisionObjects()
{
    // Define the gravity vector.
    b2Vec2 gravity(0.0f, 9.8);

    // Construct a world object, which will hold and simulate the rigid bodies.
    world = new b2World(gravity);

    // player
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(5.0f, 10.0f); // center of player
    player = world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(2.0, 6.0); // half sizes
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    player->CreateFixture(&fixtureDef);

    // createCollisionObject(QPoint(0, 100), QPoint(20, 100), 20);
    createCollisionObject(0, 40, 100, 5);

    QTimer::singleShot(3000, this, [this]{
        player->ApplyLinearImpulse(b2Vec2(0, -500),  player->GetWorldCenter(), true);
    });

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
        world->Step(1.0f / 60.0f, 8, 3);
        renderScene();
    }
}

void Model::renderScene() {
    QPixmap pixmap(width(), height());
    pixmap.fill(Qt::white);
    QPainter painter(&pixmap);

    QTransform transform;
    // transform.scale(10.0, 10.0);
    // transform.translate(0.0, -64.0);
    painter.setTransform(transform);

    painter.setPen(Qt::NoPen);

    painter.setBrush(Qt::blue);
    b2Vec2 playerPosition = player->GetPosition();
    painter.drawRect(playerPosition.x, playerPosition.y, 4, 12);
    // Render the walls
    painter.setBrush(Qt::red);
    for (const Wall& wall : collisionObjects) {
        painter.drawRect(wall.x, wall.y, wall.width, wall.height);
    }

    emit renderSceneOnView(pixmap);
}
