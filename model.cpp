// model.cpp
#include "model.h"

Model::Model(QWidget *parent)
    : QWidget(parent)
    , world(nullptr)
    , scene()
    , collisionObjects()
{
    // Define the gravity vector.
    b2Vec2 gravity(0.0f, 1920.0f);

    // Construct a world object, which will hold and simulate the rigid bodies.
    world = new b2World(gravity);

    // player
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    player = world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(50.0f, 50.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    player->CreateFixture(&fixtureDef);

    createCollisionObject(0, 400, 400, 25);

    // Connect the world timer to the worldStep() function
    connect(&worldTimer, &QTimer::timeout, this, &Model::worldStep);
    worldTimer.start(16); // 60 FPS

    moveState = stop;
    playerSpeed = 1000;
}

Model::~Model()
{
    delete world;
}

void Model::createCollisionObject(float x, float y, float w, float h)
{
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(x, y);
    b2Body* groundBody = world->CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(w, h);
    groundBody->CreateFixture(&groundBox, 0.0f);
    collisionObjects.push_back(QRect(x, y - h - 2, w, h));
}

void Model::worldStep()
{
    b2Vec2 vel = player->GetLinearVelocity();

    float desiredVel = 0;

    switch(moveState) {
        case moveLeft:
        desiredVel = -playerSpeed;
            break;
        case moveRight:
            desiredVel = playerSpeed;
            break;
        case stop:
            desiredVel = 0;
            break;
        case jump:
            float jumpImpulse = player->GetMass() * -50;
            player->ApplyLinearImpulse(b2Vec2(0, jumpImpulse), player->GetWorldCenter(), true);
            break;
    }

    float velChange = desiredVel - vel.x;
    float impulse = player->GetMass() * velChange;


    player->ApplyLinearImpulse(b2Vec2(impulse, 0), player->GetWorldCenter(), true);

    if (world) {
        world->Step(1.0f / 60.0f, 8, 3);
        renderScene();
    }
}

void Model::renderScene() {
    QPixmap pixmap(width(), height());
    pixmap.fill(Qt::white);
    QPainter painter(&pixmap);

    painter.setPen(Qt::NoPen);

    painter.setBrush(Qt::blue);
    auto position = player->GetPosition();
    painter.drawRect(position.x, position.y, 50.0, 50.0);

    painter.setBrush(Qt::red);
    for (QRect box : collisionObjects)
        painter.drawRect(box.x(), box.y(), box.width(), box.height());

    emit renderSceneOnView(pixmap);
}
