#include "doorquestiondialog.h"
#include "ui_doorquestiondialog.h"

DoorQuestionDialog::DoorQuestionDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DoorQuestionDialog)
{
    ui->setupUi(this);

    ui->Popup->hide();

    connect(ui->Response1, &QPushButton::clicked, this, &DoorQuestionDialog::onClickedResponse1);
    connect(ui->Response2, &QPushButton::clicked, this, &DoorQuestionDialog::onClickedResponse2);
    connect(ui->Response3, &QPushButton::clicked, this, &DoorQuestionDialog::onClickedResponse3);
    connect(ui->Response4, &QPushButton::clicked, this, &DoorQuestionDialog::onClickedResponse4);

    connect(ui->Popup, &QPushButton::clicked, this, &DoorQuestionDialog::hidePopUp);

    // ui->Popup->setStyleSheet(
    //     QString("QPushButton {background-color: "
    //             "rgb(255, 255, 255);} QPushButton:pressed {background-color: "
    //             "rgb(255,150,150);}"));

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

    QDialog::show();
    //displayQuestionnaire(true);
}

void DoorQuestionDialog::displayQuestionnaire(bool isDisplaying) {
    if(isDisplaying) {
        QDialog::show();
    }
    else {
        QDialog::hide();
    }
}

void DoorQuestionDialog::onClickedResponse1() {
    //qDebug() << ui->Response1->text();
    emit sendQuestionText(ui->Response1->text());
}

void DoorQuestionDialog::onClickedResponse2() {
    //qDebug() << ui->Response2->text();
    emit sendQuestionText(ui->Response2->text());
}

void DoorQuestionDialog::onClickedResponse3() {
    //qDebug() << ui->Response3->text();
    emit sendQuestionText(ui->Response3->text());
}

void DoorQuestionDialog::onClickedResponse4() {
    //qDebug() << ui->Response4->text();
    emit sendQuestionText(ui->Response4->text());
}

void DoorQuestionDialog::displayPopUp(bool response) {
    QString text = response == true ? "That is correct!" : "That is not correct!";

    ui->Popup->setText(text);
    ui->Popup->show();
}

void DoorQuestionDialog::hidePopUp() {
    ui->Popup->hide();
}
