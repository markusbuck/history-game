#ifndef PLAYER_H
#define PLAYER_H

#include <QPoint>
#include "wall.h"
#include <box2d/box2d.h>

class Player {
public:


    QPoint location;

    Player(QPoint location, b2World* world);

    void movePlayer(int x, int y);
};

#endif // PLAYER_H
