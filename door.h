#ifndef DOOR_H
#define DOOR_H

#include "wall.h"
#include <QString>
#include <Box2D/Box2D.h>
#include <QHash>

class Door {
private:

    QPoint location;
    bool isCorrect;

    b2Body* body;
public:
    Door(QPoint location, QString questionText, WorldState* worldState);
    // Door(QPoint location, QPoint point, QPoint point2, int width, QString questionText, bool isCorrect, b2World* world);
    void insertQuesionResponse(QString text, bool isCorrect);
    void insertHint(QString hint);
    bool isCorrectResponse(QString key);

    QString questionText;
    QHash<QString, bool> questionResponses;
    QList<QString> hints;
    QString generateHint(bool isCorrect);
    QString correctText;
    int width = 8, height = 16;

    int currentContacts = 0;

    b2Vec2 getTopLeft();
};



#endif // DOOR_H
