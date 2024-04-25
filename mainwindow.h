// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>
#include "model.h"
#include "player.h"
#include "doorquestiondialog.h"
#include "startleveldialogue.h"
#include "levelselect.h"
/*!
 * Authors: Kevin Soto, Zak Holt, Walker Hall, Brenden Suess, and Markus Buckwalter
 * CS 3505 Assignment 9: Educational App
 * Date: 4/24/24
 *
 * Header file for the MainWindow class
 */

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief MainWindow - Constructor for MainWindow.
     * \param m - Reference of the model.
     * \param parent - Null pointer.
     */
    MainWindow(Model& m, QWidget *parent = nullptr);

    /*!
     * \brief ~MainWindow - Decontructor for MainWindow.
     */
    ~MainWindow();

public slots:
    /*!
     * \brief onSceneRender - This slot will render the given scene.
     * \param scene - The scene to render.
     */
    void onSceneRender(QPixmap& scene);

    /*!
     * \brief keyPressEvent - This slot will change the players movement state on the key being pressed.
     * \param event - The key being pressed.
     */
    void keyPressEvent(QKeyEvent* event) override;

    /*!
     * \brief keyReleaseEvent - This slot will change the players movement state on the key being released.
     * \param event - The key being released.
     */
    void keyReleaseEvent(QKeyEvent* event) override;

signals:
    /*!
     * \brief setPlayerMoveState - This will be emitted to set the players move state.
     * \param state - The new player state.
     * \param isDown - Boolean if the key is being held down.
     */
    void setPlayerMoveState(Player::Movement state, bool isDown);

    /*!
     * \brief doorCollision - This will be emitted when the player has collided with a door.
     */
    void doorCollision();

    /*!
     * \brief updateDimensions - This will be emitted when the user has changed the windows dimensions.
     * \param width - The new width.
     * \param height - The new height.
     */
    void updateDimensions(int width, int height);

    /*!
     * \brief showDialogue - This will be emitted to show the question's dialog.
     */
    void showDialogue();

    /*!
     * \brief showMenu - Emits when esc is pressed
     */
    void showMenu();

protected:
    /*!
     * \brief paintEvent - This method will draw the scenes pixmap.
     * \param event - The QPaintEvent.
     */
    void paintEvent(QPaintEvent* event) override;

    /*!
     * \brief resizeEvent - This method will resize the games pixmap.
     * \param event - The QResizeEvent.
     */
    void resizeEvent(QResizeEvent* event) override;

    /*!
     * \brief closeEvent - This method will close the doors dialog when the game has been closed.
     * \param event - The QCloseEvent.
     */
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::MainWindow *ui;
    Model& model;

    // dialogs
    DoorQuestionDialog doorQuestionDialog;
    StartLevelDialogue startLevelDialogue;
    LevelSelect levelSelect;

    // rendering
    QPixmap scenePixmap;
    QTransform transform;
};

#endif // MAINWINDOW_H
