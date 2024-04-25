#include "levelselect.h"
#include "ui_levelselect.h"

LevelSelect::LevelSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LevelSelect)
{
    ui->setupUi(this);

    // setup level buttons
    connect(ui->level1Button, &QPushButton::clicked, this, [this](){onLevelClicked(1);});
    connect(ui->level2Button, &QPushButton::clicked, this, [this](){onLevelClicked(2);});
    connect(ui->level3Button, &QPushButton::clicked, this, [this](){onLevelClicked(3);});
    connect(ui->level4Button, &QPushButton::clicked, this, [this](){onLevelClicked(4);});
    connect(ui->backButton, &QPushButton::clicked, this, &LevelSelect::onBackClicked);

    levels.push_back(ui->level1Button);
    levels.push_back(ui->level2Button);
    levels.push_back(ui->level3Button);
    levels.push_back(ui->level4Button);

    // only enable the first one
    for(auto button : levels)
        button->setEnabled(false);
    ui->level1Button->setEnabled(true);
}

LevelSelect::~LevelSelect()
{
    delete ui;
}

void LevelSelect::onShowLevelDialog()
{
    emit hideStartDialog();
    QDialog::show();
}

void LevelSelect::onLevelClicked(int lvl)
{
    QDialog::hide();
    emit levelSelected(lvl);
}

void LevelSelect::onBackClicked()
{
    QDialog::hide();
    emit backToStart();
}

void LevelSelect::onLevelUnlocked(int lvl)
{
    levels[lvl]->setEnabled(true);
}
