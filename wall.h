#ifndef WALL_H
#define WALL_H

#include <QPoint>
#include <box2d/box2d.h>

class Wall {

public:
    // Wall(QPoint p1, QPoint p2, int width, b2World* world);
    Wall(int x, int y, int w, int h, b2World* world);
    // QPoint p1;
    // QPoint p2;
    // int thickness;

    int width, height;
    int x, y;
};

#endif // WALL_H
