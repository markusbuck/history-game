#ifndef PLAYER_H
#define PLAYER_H

#include <QPoint>
#include "wall.h"

class Player {
public:
    QPoint location;

    Player();
    Player(QPoint location);

    void movePlayer(int x, int y);
};

#endif // PLAYER_H
