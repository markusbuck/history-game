#ifndef WALL_H
#define WALL_H

#include <QPoint>
#include <box2d/box2d.h>
#include "WorldState.h"

class Wall {

public:
    Wall(float x, float y, float w, float h, WorldState* worldState);

    float x, y;
    float width, height;
};

#endif // WALL_H
