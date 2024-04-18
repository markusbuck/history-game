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
    bool isCorrect;
public:
    Door(QPoint location, Wall wall, QString questionText, bool isCorrect);
    // Door(QPoint location, QPoint point, QPoint point2, int width, QString questionText, bool isCorrect, b2World* world);
    void insertQuesionResponse(QString text, bool isCorrect);
    void insertHint(QString hint);
    bool isCorrectResponse(QString key);

    QString questionText;
    QHash<QString, bool> questionResponses;
    QList<QString> hints;
    QString generateHint(bool isCorrect);
    QString correctText;

};



#endif // DOOR_H
