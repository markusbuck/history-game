#include "wall.h"

// Wall::Wall(QPoint p1, QPoint p2, int wallThickness, b2World* world) {
//     this->thickness = wallThickness;
//     this->p1 = p1;
//     this->p2 = p2;

//     int dominantLength = qAbs(qMax((p2 - p1).x(), (p2 - p1).y())); // get the maximum based on its orientation
//     QPoint size = (p2 - p1);
//     // if the wall is horizontal, the longer side will be the width, and the height will be the thickness
//     width = qAbs(size.x()) > qAbs(size.y()) ? dominantLength : wallThickness;
//     // if the wall is vertical, the vertical height will be the correct side while the width will be the thickness
//     height = qAbs(size.x()) < qAbs(size.y()) ? dominantLength : wallThickness;

//     x = p1.x();
//     y = p1.y();

//     b2BodyDef wallBodyDef;
//     wallBodyDef.position.Set(x, y);
//     b2Body* wallBody = world->CreateBody(&wallBodyDef);
//     b2PolygonShape box;
//     box.SetAsBox(width, height);
//     wallBody->CreateFixture(&box, 0.0f);
// }

Wall::Wall(int x, int y, int w, int h, b2World* world)
    : x(x), y(y), width(w), height(h) {
    b2BodyDef wallBodyDef;
    wallBodyDef.position.Set(x + w / 2, y - h / 2);
    b2Body* wallBody = world->CreateBody(&wallBodyDef);
    b2PolygonShape box;
    box.SetAsBox(width / 2, height / 2);
    wallBody->CreateFixture(&box, 0.0f);
}
