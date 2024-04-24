#ifndef STARTLEVELDIALOGUE_H
#define STARTLEVELDIALOGUE_H

#include <QDialog>

namespace Ui {
class StartLevelDialogue;
}

class StartLevelDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit StartLevelDialogue(QWidget *parent = nullptr);
    ~StartLevelDialogue();

signals:
    void sendStartLevel();
    void retrieveContext();

public slots:
    void onClickedStartLevel();
    void onClickedContext();
    void showDialogue();
    void hidePopup();
    void setContextDialogue(QString text);

private:
    Ui::StartLevelDialogue *ui;
};

#endif // STARTLEVELDIALOGUE_H
