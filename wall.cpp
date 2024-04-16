#include "wall.h"

Wall::Wall(int x, int y, int w, int h, b2World* world)
    : x(x), y(y), width(w), height(h) {
    b2BodyDef wallBodyDef;
    wallBodyDef.position.Set(x + (float)w / 2.0, y + (float)h / 2.0);
    b2Body* wallBody = world->CreateBody(&wallBodyDef);
    b2PolygonShape box;
    box.SetAsBox((float)width / 2.0, (float)height / 2.0);
    wallBody->CreateFixture(&box, 0.0f);

}
