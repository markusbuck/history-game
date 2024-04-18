#ifndef PLAYER_H
#define PLAYER_H

#include <QPoint>
#include <box2d/box2d.h>
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
	float walkSpeed = 15.0;
	float jumpPower = 10.0;

	int currentContacts = 0;

	void movePlayer(int x, int y);

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
	void step();

signals:
	void onDoorContact();

private:
	spriteSheet sprite;
	b2Body *body;
	Movement moveState = stop;
};

#endif // PLAYER_H
