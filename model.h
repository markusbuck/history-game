// model.h
#ifndef MODEL_H
#define MODEL_H

#include <QTimer>
#include <box2d/box2d.h>
#include <QWidget>
#include <QPainter>
#include <QPixmap>

class Model : public QWidget
{
    Q_OBJECT

private:
    QTimer worldTimer;
    b2World* world;
    b2Body* dynamicBody;

    void createGround();
    void createDynamicBody();

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
