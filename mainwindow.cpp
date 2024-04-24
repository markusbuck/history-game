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
    //Context
    startLevelDialogue.setModal(true);
    //connect(&model, &Model::showInitialContextDialogue,&startLevelDialogue, &StartLevelDialogue::showDialogue);
    connect(&startLevelDialogue, &StartLevelDialogue::retrieveContext, &model, &Model::getCurrentContext);
    connect(&model, &Model::showContextDialogue, &startLevelDialogue, &StartLevelDialogue::showDialogue);
    connect(&model,&Model::sendCurrentContext, &startLevelDialogue, &StartLevelDialogue::setContextDialogue);
    connect(this, &MainWindow::showDialogue, &startLevelDialogue, &StartLevelDialogue::showDialogue);
    emit showDialogue();


    connect(&model, &Model::renderSceneOnView, this, &MainWindow::onSceneRender);
    connect(this, &MainWindow::setPlayerMoveState, &model, &Model::onPlayerMoveState);

    //door
    // connect(this, &MainWindow::doorCollision, &model, &Model::onDoorCollisionState);

    connect(&model, &Model::generateQuestionnaire, &doorQuestionDialog, &DoorQuestionDialog::onPlayerCollision);

    connect(&doorQuestionDialog, &DoorQuestionDialog::sendQuestionText, &model, &Model::isInputCorrect);

    connect(&model, &Model::displayPopUp, &doorQuestionDialog, &DoorQuestionDialog::displayPopUp);

    // connect(&doorQuestionDialog, &DoorQuestionDialog::exitDialog, &model, &Model::exitDialog);
    connect(&doorQuestionDialog, &DoorQuestionDialog::exitDialog, [this] {
        if (!doorQuestionDialog.isHidden()) {
            doorQuestionDialog.hide();
            this->model.exitDialog();
        }
    });

    connect(this, &MainWindow::updateDimensions, &model, &Model::updateDimensions);
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

void MainWindow::resizeEvent(QResizeEvent* event) {
    QSize size = event->size();
    emit updateDimensions(size.width(), size.height());
    QMainWindow::resizeEvent(event);
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

void MainWindow::closeEvent(QCloseEvent *event) {
    doorQuestionDialog.close();
}
