#ifndef LEVEL_H
#define LEVEL_H

#include <QVector>
#include <QPainter>
#include <QWidget>
#include "wall.h"
#include "door.h"
#include "player.h"
#include "WorldState.h"

/*!
 * Authors: Kevin Soto, Zak Holt, Walker Hall, Brenden Suess, and Markus Buckwalter
 * CS 3505 Assignment 9: Educational App
 * Date: 4/24/24
 *
 * Header file for the Level class
 */
class Level : public QWidget
{
    Q_OBJECT
protected:
    WorldState worldState;

    /*!
     * \brief createCollisionObject - This method will create a collision object with
     *  a given width, and height at the given location.
     * \param x - The x-coordinate.
     * \param y - The y-coordinate.
     * \param width - The width of the collision object.
     * \param height - The height of the collision object.
     */
    void createCollisionObject(int x, int y, int width, int height);
    QVector<Wall> collisionObjects;
    bool isInDialog = false;
    QImage background;
    QPoint spawnPosition;
signals:
    /*!
     * \brief generateQuestionnaire - This will be emitted to update the doors question text, and responses.
     * \param questionText - The question text to be changed to.
     * \param responses - The respones to be changed to.
     */
    void generateQuestionnaire(QString questionText, QHash<QString, bool> responses);

    /*!
     * \brief displayPopUp - This will be emitted to display the popup, on the given answer.
     * \param input - Boolean to determine if the answer is correct.
     * \param answer - The text of the hint to display.
     */
    void displayPopUp(bool input, QString answer);
public slots:
    /*!
     * \brief onDoorCollisionState - This will be emitted when the player has collided with
     * a door, and will display the doors dialog.
     */
    void onDoorCollisionState();

    /*!
     * \brief isInputCorrect - This will be emitted when the player has picked a response, determine if it's correct, and display the popup.
     * \param response - The chosen response from the player.
     */
    void isInputCorrect(QString response);

    /*!
     * \brief exitDialog - This will be emitted to close the doors dialog when the games window has been closed.
     */
    void exitDialog();
public:
    /*!
     * \brief Level - Constructor for Level.
     * \param backgroundPath - The file path of the background path.
     * \param spawnPosition - The spawn location of the player.
     */
    Level(QString backgroundPath, QPoint spawnPosition);

    /*!
     * \brief ~Level - Deconstructor for Level.
     */
    ~Level();

    /*!
     * \brief isCollidingWall - This method will determine if the player is colliding with a wall.
     * \return True if the player has collided with a wall, false otherwise.
     */
    bool isCollidingWall();

    /*!
     * \brief isCollidingDoor - This method will determine if the player is colliding with a door.
     * \return True if the player has collided with a door, false otherwise.
     */
    bool isCollidingDoor();

    /*!
     * \brief isLevelFinished - This method will determine if the player has completed the current level.
     * \return True if the player has completed the current level, false otherwise.
     */
    bool isLevelFinished();

    /*!
     * \brief isCorrectResponse - This method will determine if the players response was correct at a specified door.
     * \param response - The response the player picked.
     * \param doorIndex - The index of the door.
     * \return True if the response was correct, false otherwise.
     */
    bool isCorrectResponse(QString response, int doorIndex);

    /*!
     * \brief generateHintResponse - This method will randomly generate a hint to display on the popup.
     * \param response - The response of the player picked.
     * \param doorIndex - The index of the door.
     * \return The text of the hint to be displayed.
     */
    QString generateHintResponse(QString response,int doorIndex);

    /*!
     * \brief step - This method will render the levels scene.
     */
    void step();

    /*!
     * \brief renderBackground - This method will render the background of the level.
     * \param painter - The painter to draw.
     */
    void renderBackground(QPainter *painter);

    /*!
     * \brief render - This method will render everything it contains to the scene.
     * \param painter the painter to draw.
     */
    void render(QPainter *painter);

    /*!
     * \brief renderCustom - A method to render a custom item.
     * \param painter - The painter to draw.
     */
    virtual void renderCustom(QPainter *painter) = 0;

    /*!
     * \brief movePlayerToStart - A method to move the player to the start of the level.
     */
    void movePlayerToStart();

    QVector<Door> doors;
    Player *player;
    QString context;

};

#endif // LEVEL_H
