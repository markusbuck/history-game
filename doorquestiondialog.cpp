#include "doorquestiondialog.h"
#include "ui_doorquestiondialog.h"

DoorQuestionDialog::DoorQuestionDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DoorQuestionDialog)
{
    ui->setupUi(this);

    ui->Popup->hide();
    setWindowFlags( Qt::CustomizeWindowHint );

    connect(ui->Response1, &QPushButton::clicked, this, &DoorQuestionDialog::onClickedResponse1);
    connect(ui->Response2, &QPushButton::clicked, this, &DoorQuestionDialog::onClickedResponse2);
    connect(ui->Response3, &QPushButton::clicked, this, &DoorQuestionDialog::onClickedResponse3);
    connect(ui->Response4, &QPushButton::clicked, this, &DoorQuestionDialog::onClickedResponse4);

    connect(ui->Popup, &QPushButton::clicked, this, &DoorQuestionDialog::hidePopUp);

    connect(this, &QDialog::rejected, this, &DoorQuestionDialog::onTerminated);
}

DoorQuestionDialog::~DoorQuestionDialog()
{
    delete ui;
}


void DoorQuestionDialog::onPlayerCollision(QString questionText, QHash<QString, bool> responses) {
    QList<QString> responseText = responses.keys();

    ui->Question->setText(questionText);
    ui->Response1->setText(responseText.at(0));
    ui->Response2->setText(responseText.at(1));
    ui->Response3->setText(responseText.at(2));
    ui->Response4->setText(responseText.at(3));

    qDebug() << "Dialog:OnPlayerCollision";

    QDialog::show();
}

void DoorQuestionDialog::onClickedResponse1() {
    emit sendQuestionText(ui->Response1->text());
}

void DoorQuestionDialog::onClickedResponse2() {
    emit sendQuestionText(ui->Response2->text());
}

void DoorQuestionDialog::onClickedResponse3() {
    emit sendQuestionText(ui->Response3->text());
}

void DoorQuestionDialog::onClickedResponse4() {
    emit sendQuestionText(ui->Response4->text());
}

void DoorQuestionDialog::displayPopUp(bool response, QString answer) {
    qDebug() << "Dialog:displayPopUp";

    QString text = response == true ? "That is correct!\n" : "That is not correct!\n";
    text += answer;

    doCloseAfterPopup = response;

    toggleResponseButtons(false);

    if(response) {
        ui->Popup->setStyleSheet(
            QString("QPushButton {color: white; background-color: "
                    "rgb(0, 153, 0);} QPushButton:pressed {background-color: "
                    "rgb(0,204,0);}")); ui->Popup->setText(text);
    }

    else {
        ui->Popup->setStyleSheet(
            QString("QPushButton {color: white; background-color: "
                    "rgb(255, 0, 0);} QPushButton:pressed {background-color: "
                    "rgb(255,51,51);}"));    ui->Popup->setText(text);
    }

    ui->Popup->show();
}

void DoorQuestionDialog::hidePopUp() {
    ui->Popup->hide();
    toggleResponseButtons(true);

    if (doCloseAfterPopup) {
        doCloseAfterPopup = false;
        emit exitDialog();
    }
}

void DoorQuestionDialog::toggleResponseButtons(bool toggle) {
    ui->Response1->setEnabled(toggle);
    ui->Response2->setEnabled(toggle);
    ui->Response3->setEnabled(toggle);
    ui->Response4->setEnabled(toggle);
}

void DoorQuestionDialog::onTerminated() {
    hidePopUp();

    emit exitDialog();
}
