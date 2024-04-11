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
#include "wall.h"

class Model : public QWidget
{
    Q_OBJECT

private:
    QTimer worldTimer;
    b2World* world;

    // void createCollisionObject(QPoint p1, QPoint p2, int width);
    void createCollisionObject(int x, int y, int w, int h);

    QVector<Wall> collisionObjects;
    b2Body* player;

    QPixmap scene;

    void renderScene();

public:
    Model(QWidget *parent = nullptr);
    ~Model();

signals:
    void renderSceneOnView(QPixmap& scene);

private slots:
    void worldStep();
};

#endif // MODEL_H
