// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>
#include "model.h"
#include "player.h"
#include "doorquestiondialog.h"
#include "startleveldialogue.h"
#include "levelselect.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Model& m, QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void onSceneRender(QPixmap& scene);
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

signals:
    void setPlayerMoveState(Player::Movement state, bool isDown);
    void doorCollision();
    void updateDimensions(int width, int height);
    void showDialogue();

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui;
    Model& model;
    QPixmap scenePixmap;
    DoorQuestionDialog doorQuestionDialog;
    StartLevelDialogue startLevelDialogue;
    LevelSelect levelSelect;
    QTransform transform;
};

#endif // MAINWINDOW_H
