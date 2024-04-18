#ifndef LEVEL_H
#define LEVEL_H

#include "wall.h"
#include "door.h"
#include <QVector>
#include "player.h"

class Level {
private:
    QVector<Wall> walls;
public:
    bool isCollidingWall();
    bool isCollidingDoor();
    bool isLevelFinished();
    bool isCorrectResponse(QString response);
    QVector<Door> doors;

    Level(QVector<Wall> walls, QVector<Door> Doors);
};

#endif // LEVEL_H
