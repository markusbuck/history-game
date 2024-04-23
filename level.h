#ifndef LEVEL_H
#define LEVEL_H

#include "wall.h"
#include "door.h"
#include <QVector>
#include "player.h"
#include "WorldState.h"
#include <QPainter>
#include <QWidget>

class Level : public QWidget
{
    Q_OBJECT
protected:
    WorldState worldState;
    void createCollisionObject(int x, int y, int width, int height);
    QVector<Wall> collisionObjects;
signals:
    void generateQuestionnaire(QString questionText, QHash<QString, bool> responses);
    void displayPopUp(bool input, QString answer);
public slots:
    void onDoorCollisionState();
    void isInputCorrect(QString response);
public:
    Level();

    bool isCollidingWall();
    bool isCollidingDoor();
    bool isLevelFinished();
    bool isCorrectResponse(QString response, int doorIndex);
    QString generateHintResponse(QString response,int doorIndex);

    void step();
    void render(QPainter *painter);

    QVector<Door> doors;
    Player *player;
};

#endif // LEVEL_H
