#include "startleveldialogue.h"
#include "ui_startleveldialogue.h"
#include <QDialog>

StartLevelDialogue::StartLevelDialogue(QWidget *parent) :
    QDialog(parent), ui(new Ui::StartLevelDialogue)
{
    ui->setupUi(this);
    connect(ui->startLevel, &QPushButton::clicked, this, &StartLevelDialogue::onClickedStartLevel);
    connect(ui->popUp,&QPushButton::clicked, this, &StartLevelDialogue::hidePopup);
    connect(ui->context,&QPushButton::clicked, this, &StartLevelDialogue::onClickedContext);
    connect(ui->levelSelect, &QPushButton::clicked, this, &StartLevelDialogue::onLevelsClicked);
    this->hidePopup();
}

void StartLevelDialogue::onClickedStartLevel() {
    this->hide();
}

void StartLevelDialogue::showDialogue() {

    ui->startLevel->setText("Start");
    QDialog::show();
    emit retrieveContext();
}

void StartLevelDialogue::hidePopup() {
    ui->popUp->hide();
}

void StartLevelDialogue::setContextDialogue(QString text) {
    ui->popUp->setText(text);
}

void StartLevelDialogue::onClickedContext() {
    ui->popUp->setStyleSheet(
        QString("QPushButton {color: white; background-color: "
                "rgb(16, 80, 80);} QPushButton:pressed {background-color: "
                "rgb(60,80,80);}"));
    ui->popUp->show();
}

void StartLevelDialogue::onLevelsClicked() {
    QDialog::hide();
    emit showLevelSelect();
}

StartLevelDialogue::~StartLevelDialogue() {
    delete ui;
}

void StartLevelDialogue::onShowMenu() {
    ui->startLevel->setText("Resume");
    QDialog::show();
    emit retrieveContext();
}

void StartLevelDialogue::showPreviousDialog() {
    QDialog::show();
    emit retrieveContext();
}

