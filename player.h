#ifndef PLAYER_H
#define PLAYER_H

#include <QPoint>
#include <Box2D/Box2D.h>
#include <QMap>
#include <QSoundEffect>
#include <QUrl>
#include "WorldState.h"
#include "QObject"
#include "spritesheet.h"

/*!
 * Authors: Kevin Soto, Zak Holt, Walker Hall, Brenden Suess, and Markus Buckwalter
 * CS 3505 Assignment 9: Educational App
 * Date: 4/24/24
 *
 * Header file for the Player class
 */
class Player : public QObject
{
	Q_OBJECT
public:
    /*!
     * \brief Player - Constructor for Player.
     * \param location - The location to spawn the player.
     * \param worldState - The world state.
     */
	Player(QPoint location, WorldState *worldState);

	const int width, height;

    // used for if player is grounded
    int currentContacts = 0;

    // player properties
    float walkSpeed = 35.0;
    float jumpPower = 80.0;

    /*!
     * \brief render - This method will render the player to the screen.
     * \param painter - A pointer of the painter.
     */
	void render(QPainter *painter);

	// b2Body methods
    /*!
     * \brief getVelocity - This method will get the velocity of the player.
     * \return a b2Vec2 of the players velocity.
     */
	b2Vec2 getVelocity();

    /*!
     * \brief applyImpulse - This method will apply an impulse to the player.
     * \param impulse - The impulse.
     * \param position - The position.
     */
	void applyImpulse(b2Vec2 impulse, b2Vec2 position);
    void applyForce(b2Vec2 force);

    /*!
     * \brief getMass - This method will get the mass of the player.
     * \return The mass of the player.
     */
	float getMass();

    /*!
     * \brief getCenter - This method will get the center of the player.
     * \return The center of the player.
     */
	b2Vec2 getCenter();

    /*!
     * \brief getTopLeft - This method will get the top left of the player.
     * \return b2Vec2 of the top left of the player.
     */
	b2Vec2 getTopLeft();

	// state update
    /*!
     * \brief The Movement enum - The states the players movements.
     */
	enum Movement
	{
		keyLeft,
		keyRight,
		jump,
		stop
	};

    /*!
     * \brief setMoveState - This method will set the players move state.
     * \param state - The state to be changed to.
     * \param isDown - Boolean to determine if the key is down.
     */
    void setMoveState(Movement state, bool isDown);
	QMap<Movement, bool> movementStates;

	// physics update
    /*!
     * \brief step - This method will update the player position.
     */
    void step(float);

    /*!
     * \brief setPosition - Set the position of the player.
     * \param position - The location to move the player to.
     */
    void setPosition(QPoint position);

signals:
    /*!
     * \brief onDoorContact - This will be emitted when the player has hit a door.
     */
	void onDoorContact();

private:
	spriteSheet sprite;
	b2Body *body;
	Movement moveState = stop;
    float elapsedSinceLastFrame;
    QSoundEffect jumpSound;
};

#endif // PLAYER_H
