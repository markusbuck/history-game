#ifndef PLAYER_H
#define PLAYER_H

#include <QPoint>
#include <box2d/box2d.h>
#include <QMap>

class Player {
public:
    Player(QPoint location, b2World* world);

    const int width, height;
    float walkSpeed = 15.0;
    float jumpPower = 10.0;

    void movePlayer(int x, int y);

    // b2Body methods
    b2Vec2 getVelocity();
    void applyImpulse(b2Vec2 impulse, b2Vec2 position);
    float getMass();
    b2Vec2 getCenter();
    b2Vec2 getTopLeft();

    // state update
    enum Movement {keyLeft, keyRight, jump, stop};
    void setMoveState(Movement state, bool isDown);
    QMap<Movement, bool> movementStates;

    // physics update
    void step();
private:
    b2Body* body;
    Movement moveState = stop;
};

#endif // PLAYER_H
