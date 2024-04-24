#ifndef STARTLEVELDIALOGUE_H
#define STARTLEVELDIALOGUE_H

#include <QDialog>
/*!
 * Authors: Kevin Soto, Zak Holt, Walker Hall, Brenden Suess, and Markus Buckwalter
 * CS 3505 Assignment 9: Educational App
 * Date: 4/24/24
 *
 * Header file for the startLevelDialog that is part of a level.
 */

namespace Ui {
class StartLevelDialogue;
}

class StartLevelDialogue : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief StartLevelDialogue - Constructor for StartLevelDialog.
     * \param parent - Null pointer.
     */
    explicit StartLevelDialogue(QWidget *parent = nullptr);

    /*!
     * \brief ~StartLevelDialog - Deconstructor for StartLevelDialog.
     */
    ~StartLevelDialogue();

signals:
    /*!
     * \brief sendStartLevel - This will emit a signal to display the dialog when started.
     */
    void sendStartLevel();

    /*!
     * \brief retrieveContext - This will emit a signal to get the contents of the level.
     */
    void retrieveContext();
    void showLevelSelect();

public slots:
    /*!
     * \brief onClickedStartLevel - This slot will hide the dialog when the start level button has been pressed.
     */
    void onClickedStartLevel();

    /*!
     * \brief onClickedContext - This slot will display a popup containing its
     * context when the level background information is pressed.
     */
    void onClickedContext();
    void onLevelsClicked();

    /*!
     * \brief showDialogue - This slot will display the dialog.
     */
    void showDialogue();

    /*!
     * \brief hidePopup - This slot will hide the popup for the levels background information.
     */
    void hidePopup();

    /*!
     * \brief setContextDialogue - This slot will change the context's dialog to the given text.
     * \param text - The text to be changed to.
     */
    void setContextDialogue(QString text);

    void onShowMenu();

private:
    Ui::StartLevelDialogue *ui;
};

#endif // STARTLEVELDIALOGUE_H
