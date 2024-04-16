#ifndef DOOR_H
#define DOOR_H

#include "wall.h"
#include <QString>
#include <box2d/box2d.h>
#include <QHash>

class Door {
private:
    QPoint location;
    Wall hitBox;
    QString questionText;
    QHash<QString, bool> questionResponses;
    bool isCorrect;
public:
    Door(QPoint location, Wall wall, QString questionText, bool isCorrect);
    // Door(QPoint location, QPoint point, QPoint point2, int width, QString questionText, bool isCorrect, b2World* world);
    void insertQuesionResponse(QString text, bool isCorrect);

    bool isCorrectResponse(QString key);






};



#endif // DOOR_H
