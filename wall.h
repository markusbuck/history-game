#ifndef WALL_H
#define WALL_H

#include <QPoint>
#include <box2d/box2d.h>

class Wall {

public:
    Wall(float x, float y, float w, float h, b2World* world);

    float x, y;
    float width, height;
};

#endif // WALL_H
