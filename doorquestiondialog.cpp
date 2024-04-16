#include "doorquestiondialog.h"
#include "ui_doorquestiondialog.h"

DoorQuestionDialog::DoorQuestionDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DoorQuestionDialog)
{
    ui->setupUi(this);
}

DoorQuestionDialog::~DoorQuestionDialog()
{
    delete ui;
}


void DoorQuestionDialog::onPlayerCollision() {
    emit toggleQuesionnaire(true);
}
