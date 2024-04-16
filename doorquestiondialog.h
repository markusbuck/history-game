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

private:
    Ui::DoorQuestionDialog *ui;

public slots:
    void onPlayerCollision();
signals:
    void toggleQuesionnaire(bool toggle);
    void onResponseChoice(QString key);
};

#endif // DOORQUESTIONDIALOG_H
