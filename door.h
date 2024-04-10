#ifndef DOOR_H
#define DOOR_H

#include "wall.h"
#include <QString>

class Door {
private:
    QPoint location;
    Wall hitBox;
    QString questionText;
    bool isCorrect;
public:
    Door(QPoint location, Wall wall, QString questionText, bool isCorrect);
    Door(QPoint location, QPoint point, QPoint point2, int width, QString questionText, bool isCorrect);
};



#endif // DOOR_H
