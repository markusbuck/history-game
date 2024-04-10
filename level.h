#ifndef LEVEL_H
#define LEVEL_H

#include "wall.h"
#include "door.h"
#include <QVector>
#include "player.h"

class Level {
private:
    Player player;
    QVector<Wall> walls;
    QVector<Door> doors;
public:
    bool isCollidingWall();
    bool isCollidingDoor();
    bool isLevelFinished();
};

#endif // LEVEL_H
