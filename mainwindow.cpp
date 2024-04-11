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

    connect(&model, &Model::renderSceneOnView, this, &MainWindow::onSceneRender);
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
        case Qt::Key_Left:

        this->model.moveState = Model::moveLeft;
            break;
        case Qt::Key_Right:
            this->model.moveState = Model::moveRight;
            break;
        case Qt::Key_Up:
            qDebug() << "jump";
            this->model.moveState = Model::jump;
            break;

    }
}

void MainWindow::keyReleaseEvent(QKeyEvent* event) {
    switch(event->key()) {
    case Qt::Key_Left:
        this->model.moveState = Model::stop;
        break;
    case Qt::Key_Right:
        this->model.moveState = Model::stop;
        break;
    // case Qt::Key_Up:
    //     this->model.moveState = Model::stop;
    //     break;
    }
}
