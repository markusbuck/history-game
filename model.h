// model.h
#ifndef MODEL_H
#define MODEL_H

#include <QTimer>
#include <box2D/box2D.h>
#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QVector>
#include <QRect>
#include "wall.h"
#include "player.h"
#include <QElapsedTimer>
#include "WorldState.h"
#include "level.h"
/*!
 * Authors: Kevin Soto, Zak Holt, Walker Hall, Brenden Suess, and Markus Buckwalter
 * CS 3505 Assignment 9: Educational App
 * Date: 4/24/24
 *
 * Header file for the model class
 */

class Model : public QWidget
{
    Q_OBJECT

private:

    QTimer worldTimer;

    QPixmap scene;
    QPainter painter;

    Level *currentLevel;
    QList<Level*> levels;
    int currentLevelIndex = 0;

    QElapsedTimer elapsedTimer;
    qint64 lastFrameTime = 0;
    const qint64 FRAME_TIME_TARGET = 1e9 / 60;

    /*!
     * \brief renderScene - This method will render the current level, and player to the scene.
     */
    void renderScene();

    b2Vec2 windowDimensions;

    /*!
     * \brief setupLevel - This method will update the doors dialog to the current level's question text, and responses.
     * \param level - The level to be updated.
     */
    void setupLevel(Level *level);

public:
    /*!
     * \brief Model - Constructor for Model.
     * \param parent - Null pointer.
     */
    Model(QWidget *parent = nullptr);

    /*!
     * \brief ~Model - Deconstructor for Model.
     */
    ~Model();
signals:
    /*!
     * \brief renderSceneOnView - This will be emitted to render the current scene, and display it.
     * \param scene - The scene to render.
     */
    void renderSceneOnView(QPixmap& scene);

    /*!
     * \brief generateQuestionnaire - This will be emitted to generate the doors
     * questionnaire with the given question text, and responses.
     * \param questionText - The text to update.
     * \param responses - The responses to update.
     */
    void generateQuestionnaire(QString questionText, QHash<QString, bool> responses);

    /*!
     * \brief displayPopUp - This will be emitted to display the popup on a chosen response.
     * \param input - A boolean to determine which type of popup to display.
     * \param answer - The hint to display on the popup.
     */
    void displayPopUp(bool input, QString answer);

    /*!
     * \brief sendCurrentContext - This will be emitted to change the contexts information.
     * \param context - The updated information to be displayed.
     */
    void sendCurrentContext(QString context);

    /*!
     * \brief showContextDialogue - This will be emitted to display the context dialog.
     */
    void showContextDialogue();
    //void showInitialContextDialogue();

public slots:
    /*!
     * \brief worldStep - This slot will update the scene.
     */
    void worldStep();

    /*!
     * \brief onPlayerMoveState - This slot will change the players movement.
     * \param state - The state to be changed to.
     * \param isDown - Boolean to determine if the key is down.
     */
    void onPlayerMoveState(Player::Movement state, bool isDown);

    /*!
     * \brief isInputCorrect - This slot will determine if the players input was correct on the doors dialog.
     * \param response - The response the user has pressed.
     */
    void isInputCorrect(QString response);

    /*!
     * \brief exitDialog - This slot will close the doors dialog when closed.
     */
    void exitDialog();

    /*!
     * \brief updateDimensions - This slot will update the games window size.
     * \param width - The width of the window.
     * \param height - The height of the window.
     */
    void updateDimensions(int width, int height);

    /*!
     * \brief getCurrentContext - This slot will get the context of the current level.
     */
    void getCurrentContext();

};

#endif // MODEL_H
