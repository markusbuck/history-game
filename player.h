#ifndef PLAYER_H
#define PLAYER_H

#include <QPoint>
#include "wall.h"

class Player {
private:
    QPoint location;

    Wall hitBox;
public:
    Player(QPoint location, Wall hitBox);

    void movePlayer(int x, int y);
};

#endif // PLAYER_H
