// model.cpp
#include "model.h"

Model::Model(QWidget *parent)
    : QWidget(parent)
    , world(nullptr)
    , dynamicBody(nullptr)
    , scene()
{
    // Define the gravity vector.
    b2Vec2 gravity(0.0f, -10.0f);

    // Construct a world object, which will hold and simulate the rigid bodies.
    world = new b2World(gravity);

    createGround();
    createDynamicBody();

    // Connect the world timer to the worldStep() function
    connect(&worldTimer, &QTimer::timeout, this, &Model::worldStep);
    worldTimer.start(16); // 60 FPS
}

Model::~Model()
{
    delete world;
}

void Model::createGround()
{
    // Create a ground body
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);
    b2Body* groundBody = world->CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);
}

void Model::createDynamicBody()
{
    // Create a dynamic body
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    dynamicBody = world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    dynamicBody->CreateFixture(&fixtureDef);
}

void Model::worldStep()
{
    if (world && dynamicBody) {
        world->Step(1.0f / 60.0f, 8, 3);
        renderScene();
    }
}

void Model::renderScene() {
    QPixmap pixmap(width(), height());
    pixmap.fill(Qt::white);  // Fill the background with white color

    QPainter painter(&pixmap);
    painter.setPen(Qt::NoPen);  // No outline
    painter.setBrush(Qt::red);  // Set the brush color to red

    // Draw a small red box at the center of the pixmap
    int boxSize = 50;
    int x = (pixmap.width() - boxSize) / 2;
    int y = (pixmap.height() - boxSize) / 2;
    painter.drawRect(x, y, boxSize, boxSize);

    emit renderSceneOnView(pixmap);
}
