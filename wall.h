#ifndef WALL_H
#define WALL_H

#include <QPoint>
#include <box2d/box2d.h>

class Wall {

public:
    Wall(int x, int y, int w, int h, b2World* world);

    int width, height;
    int x, y;
};

#endif // WALL_H
