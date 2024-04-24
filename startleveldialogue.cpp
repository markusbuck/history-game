#include "startleveldialogue.h"
#include "ui_startleveldialogue.h"
#include <QDialog>

StartLevelDialogue::StartLevelDialogue(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StartLevelDialogue)
{

    ui->setupUi(this);
    connect(ui->startLevel, &QPushButton::clicked, this, &StartLevelDialogue::onClickedStartLevel);
    connect(ui->popUp,&QPushButton::clicked, this, &StartLevelDialogue::hidePopup);
    connect(ui->context,&QPushButton::clicked, this, &StartLevelDialogue::onClickedContext);
    this->hidePopup();
}

void StartLevelDialogue::onClickedStartLevel(){
    this->hide();
}
void StartLevelDialogue::showDialogue(){

    QDialog::show();
    emit retrieveContext();
}
void StartLevelDialogue::hidePopup(){
    ui->popUp->hide();
}
void StartLevelDialogue::setContextDialogue(QString text){
    ui->popUp->setText(text);
}
void StartLevelDialogue::onClickedContext(){
    // ui->context->show();
    // ui->context->hide();
    // ui->startLevel->hide();
    ui->popUp->setStyleSheet(
        QString("QPushButton {color: white; background-color: "
                "rgb(16, 80, 80);} QPushButton:pressed {background-color: "
                "rgb(60,80,80);}"));
    ui->popUp->show();
}

StartLevelDialogue::~StartLevelDialogue()
{
    delete ui;
}
