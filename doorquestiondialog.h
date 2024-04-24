#ifndef DOORQUESTIONDIALOG_H
#define DOORQUESTIONDIALOG_H

#include <QDialog>
/*!
 * Authors: Kevin Soto, Zak Holt, Walker Hall, Brenden Suess, and Markus Buckwalter
 * CS 3505 Assignment 9: Educational App
 * Date: 4/24/24
 *
 * Header file for the question dialog that is a part of the door.
 */
namespace Ui {
class DoorQuestionDialog;
}

class DoorQuestionDialog : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief DoorQuestionDialog Constructor for DoorQuestionDialog.
     * \param parent - Null pointer.
     */
    explicit DoorQuestionDialog(QWidget *parent = nullptr);

    /*!
     * \brief ~DoorQuestionDialog - Deconstructor for DoorQuestionDialog.
     */
    ~DoorQuestionDialog();

    /*!
     * \brief toggleResponseButtons - This method will toggle the buttons pressability with the passed in boolean.
     * \param toggle - A boolean to toggle the buttons.
     */
    void toggleResponseButtons(bool toggle);

private:
    Ui::DoorQuestionDialog *ui;

    bool doCloseAfterPopup = false;

public slots:
    /*!
     * \brief onPlayerCollision - The slot will change the buttons text
     * to the passed in responses, and will change the label to the given text.
     * \param questionText - The text of the question to display.
     * \param responses - The text of the responses to the question.
     */
    void onPlayerCollision(QString questionText, QHash<QString, bool> responses);

    /*!
     * \brief onClickedResponse1 - A slot that will emit a signal with the buttons text when pressed.
     */
    void onClickedResponse1();

    /*!
     * \brief onClickedResponse2 - A slot that will emit a signal with the buttons text when pressed.
     */
    void onClickedResponse2();

    /*!
     * \brief onClickedResponse3 - A slot that will emit a signal with the buttons text when pressed.
     */
    void onClickedResponse3();

    /*!
     * \brief onClickedResponse4 - A slot that will emit a signal with the buttons text when pressed.
     */
    void onClickedResponse4();

    /*!
     * \brief displayPopUp - This slot will will display a hidden popup
     * showing the user if the button they pressed was correct.
     * \param response - The boolean to determine if the button pressed is correct.
     * \param answer - A string containing a response to display on the popup.
     */
    void displayPopUp(bool response, QString answer);

    /*!
     * \brief hidePopUp - This slot will hide the popup when pressed.
     */
    void hidePopUp();

    /*!
     * \brief onTerminated - This slots will hide the
     * popup, and emit a signal to close the dialog when the dialog is terminated.
     */
    void onTerminated();

signals:

    /*!
     * \brief toggleQuestionnaire - This signal will be emitted with a boolean to display the dialog.
     * \param toggle - A bool to determine whether to hide the dialog.
     */
    void toggleQuestionnaire(bool toggle);

    /*!
     * \brief sendQuestionText - A signal to send the chosen button response text.
     * \param questionText - The text of the button.
     */
    void sendQuestionText(QString questionText);

    /*!
     * \brief exitDialog - A signal to close the dialog.
     */
    void exitDialog();
};

#endif // DOORQUESTIONDIALOG_H
