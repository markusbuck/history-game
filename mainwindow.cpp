// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

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
