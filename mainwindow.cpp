// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
 #include <QKeyEvent>
#include <QPainter>

MainWindow::MainWindow(Model& model, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(model)
{
    ui->setupUi(this);

    //doorQuestionDialog.setModal(true);
    //doorQuestionDialog.show();
    //doorQuestionDialog.hide();

    connect(&model, &Model::renderSceneOnView, this, &MainWindow::onSceneRender);
    connect(this, &MainWindow::setPlayerMoveState, &model, &Model::onPlayerMoveState);

    //door
    // connect(this, &MainWindow::doorCollision, &model, &Model::onDoorCollisionState);

    connect(&model, &Model::generateQuestionnaire, &doorQuestionDialog, &DoorQuestionDialog::onPlayerCollision);

    connect(&doorQuestionDialog, &DoorQuestionDialog::sendQuestionText, &model, &Model::isInputCorrect);

    connect(&model, &Model::displayPopUp, &doorQuestionDialog, &DoorQuestionDialog::displayPopUp);

    connect(&doorQuestionDialog, &DoorQuestionDialog::exitDialog, &model, &Model::exitDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, scenePixmap); // Draw the stored QPixmap
}

void MainWindow::onSceneRender(QPixmap& scene)
{
    scenePixmap = scene;
    update();
}

void MainWindow::keyPressEvent(QKeyEvent* event) {
    switch(event->key()) {
        // arrow keys
        case Qt::Key_Left:
            emit setPlayerMoveState(Player::Movement::keyLeft, true);
            break;
        case Qt::Key_Right:
            emit setPlayerMoveState(Player::Movement::keyRight, true);
            break;
        case Qt::Key_Up:
            emit setPlayerMoveState(Player::Movement::jump, true);
            break;
        // a, d, space
        case Qt::Key_A:
            emit setPlayerMoveState(Player::Movement::keyLeft, true);
            break;
        case Qt::Key_D:
            emit setPlayerMoveState(Player::Movement::keyRight, true);
            break;
        case Qt::Key_Space:
            emit setPlayerMoveState(Player::Movement::jump, true);
            break;
        // case Qt::Key_P:
        //     emit doorCollision();
        //     break;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent* event) {
    switch(event->key()) {
        // arrow keys
        case Qt::Key_Left:
            emit setPlayerMoveState(Player::Movement::keyLeft, false);
            break;
        case Qt::Key_Right:
            emit setPlayerMoveState(Player::Movement::keyRight, false);
            break;
        case Qt::Key_Up:
            emit setPlayerMoveState(Player::Movement::jump, false);
            break;
        // a, d, space
        case Qt::Key_A:
            emit setPlayerMoveState(Player::Movement::keyLeft, false);
            break;
        case Qt::Key_D:
            emit setPlayerMoveState(Player::Movement::keyRight, false);
            break;
        case Qt::Key_Space:
            emit setPlayerMoveState(Player::Movement::jump, false);
            break;
    }
}
