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

class Model : public QWidget
{
    Q_OBJECT

private:

    QTimer worldTimer;
    b2World* world;

    // void createCollisionObject(QPoint p1, QPoint p2, int width);
    void createCollisionObject(int x, int y, int w, int h);

    QVector<Wall> collisionObjects;
    Player* player;
    float playerSpeed = 0;
    QPixmap scene;

    void renderScene();

public:
    Model(QWidget *parent = nullptr);
    ~Model();

signals:
    void renderSceneOnView(QPixmap& scene);

public slots:
    void worldStep();
    void onPlayerMoveState(Player::Movement state);
};

#endif // MODEL_H
