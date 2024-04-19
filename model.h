// model.h
#ifndef MODEL_H
#define MODEL_H

#include <QTimer>
#include <box2D/box2D.h>
#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QVector>
#include <QRect>
#include "wall.h"
#include "player.h"
#include <QElapsedTimer>
#include "WorldState.h"
#include "level.h"


class Model : public QWidget
{
    Q_OBJECT

private:

    QTimer worldTimer;
    b2World* world;
    WorldState worldState;
    ContactListener *worldContact;

    // void createCollisionObject(QPoint p1, QPoint p2, int width);
    void createCollisionObject(int x, int y, int w, int h);

    QVector<Wall> collisionObjects;
    Player* player;
    float playerSpeed = 0;

    QPixmap scene;
    QPainter painter;

    int currentLevel = 0;
    QList<Level> levels;
    bool isInDialog = false;

    QElapsedTimer elapsedTimer;
    qint64 lastFrameTime = 0;
    const qint64 FRAME_TIME_TARGET = 1e9 / 60;

    void renderScene();

public:
    Model(QWidget *parent = nullptr);
    ~Model();

signals:
    void renderSceneOnView(QPixmap& scene);
    void generateQuestionnaire(QString questionText, QHash<QString, bool> responses);
    void displayPopUp(bool input, QString answer);
public slots:
    void worldStep();
    void onPlayerMoveState(Player::Movement state, bool isDown);
    void onDoorCollisionState();
    void isInputCorrect(QString response);
    void exitDialog();
};

#endif // MODEL_H
