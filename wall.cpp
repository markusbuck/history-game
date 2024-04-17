#include "wall.h"

Wall::Wall(float x, float y, float w, float h, WorldState* worldState)
    : x(x), y(y), width(w), height(h) {
    b2BodyDef wallBodyDef;
    wallBodyDef.position.Set(x + w / 2.0, y + h / 2.0);
    b2Body* wallBody = worldState->world->CreateBody(&wallBodyDef);
    b2PolygonShape box;
    box.SetAsBox(width / 2.0, height / 2.0);
    wallBody->CreateFixture(&box, 0.0f);
}
