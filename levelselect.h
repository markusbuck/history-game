#ifndef LEVELSELECT_H
#define LEVELSELECT_H

#include <QDialog>

namespace Ui {
class LevelSelect;
}

class LevelSelect : public QDialog
{
    Q_OBJECT

public:
    explicit LevelSelect(QWidget *parent = nullptr);
    ~LevelSelect();

public slots:
    void onLevelClicked(int level);
    void onBackClicked();
    void onShowLevelDialog();
    void onLevelUnlocked(int lvl);
signals:
    void backToStart();
    void hideStartDialog();
    void levelSelected(int lvl);
private:
    Ui::LevelSelect *ui;
    QList<QPushButton*> levels;
};

#endif // LEVELSELECT_H
