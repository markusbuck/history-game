#ifndef DOORQUESTIONDIALOG_H
#define DOORQUESTIONDIALOG_H

#include <QDialog>

namespace Ui {
class DoorQuestionDialog;
}

class DoorQuestionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DoorQuestionDialog(QWidget *parent = nullptr);
    ~DoorQuestionDialog();
    void toggleResponseButtons(bool toggle);

private:
    Ui::DoorQuestionDialog *ui;
    bool doCloseAfterPopup = false;

public slots:
    void onPlayerCollision(QString questionText, QHash<QString, bool> responses);
    void onClickedResponse1();
    void onClickedResponse2();
    void onClickedResponse3();
    void onClickedResponse4();
    void displayPopUp(bool response, QString answer);
    void hidePopUp();
    void onTerminated();

signals:
    void toggleQuestionnaire(bool toggle);
    void onResponseChoice(QString key);
    void sendQuestionText(QString questionText);
    void exitDialog();
};

#endif // DOORQUESTIONDIALOG_H
