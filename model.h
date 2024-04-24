// model.h
#ifndef MODEL_H
#define MODEL_H

#include <QTimer>
#include <Box2D/Box2D.h>
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

    QPixmap scene;
    QPainter painter;

    Level *currentLevel;
    QList<Level*> levels;
    int currentLevelIndex = 0;

    QElapsedTimer elapsedTimer;
    qint64 lastFrameTime = 0;
    const qint64 FRAME_TIME_TARGET = 1e9 / 60;

    void renderScene();

    b2Vec2 windowDimensions;

    void setupLevel(Level *level);

public:
    Model(QWidget *parent = nullptr);
    ~Model();

signals:
    void renderSceneOnView(QPixmap& scene);
    void generateQuestionnaire(QString questionText, QHash<QString, bool> responses);
    void displayPopUp(bool input, QString answer);
    void sendCurrentContext(QString context);
    void showContextDialogue();
    void unlockLevel(int lvl);
    //void showInitialContextDialogue();

public slots:
    void worldStep();
    void onPlayerMoveState(Player::Movement state, bool isDown);
    void isInputCorrect(QString response);
    void exitDialog();
    void updateDimensions(int width, int height);
    void getCurrentContext();
    void onLevelSelected(int lvl);

};

#endif // MODEL_H
