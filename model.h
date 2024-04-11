// model.h
#ifndef MODEL_H
#define MODEL_H

#include <QTimer>
#include <box2d/box2d.h>
#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QVector>
#include <QRect>

class Model : public QWidget
{
    Q_OBJECT

private:

    QTimer worldTimer;
    b2World* world;

    void createCollisionObject(float x, float y, float w, float h);

    QVector<QRect> collisionObjects;
    b2Body* player;
    float playerSpeed = 0;
    QPixmap scene;

    void renderScene();

public:
    Model(QWidget *parent = nullptr);
    ~Model();
    enum Movement {moveLeft, moveRight, jump, stop};
    Movement moveState;

signals:
    void renderSceneOnView(QPixmap& scene);

private slots:
    void worldStep();
};

#endif // MODEL_H
