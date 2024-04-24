#ifndef PLAYER_H
#define PLAYER_H

#include <QPoint>
#include <Box2D/Box2D.h>
#include <QMap>
#include "WorldState.h"
#include "QObject"
#include "spritesheet.h"

class Player : public QObject
{
	Q_OBJECT
public:
	Player(QPoint location, WorldState *worldState);

	const int width, height;
    float walkSpeed = 35.0;
    float jumpPower = 50.0;

	int currentContacts = 0;

	void render(QPainter *painter);

	// b2Body methods
	b2Vec2 getVelocity();
	void applyImpulse(b2Vec2 impulse, b2Vec2 position);
	float getMass();
	b2Vec2 getCenter();
	b2Vec2 getTopLeft();

	// state update
	enum Movement
	{
		keyLeft,
		keyRight,
		jump,
		stop
	};
	void setMoveState(Movement state, bool isDown);
	QMap<Movement, bool> movementStates;

	// physics update
    void step(float);

signals:
	void onDoorContact();

private:
	spriteSheet sprite;
	b2Body *body;
	Movement moveState = stop;
    float elapsedSinceLastFrame;
};

#endif // PLAYER_H
