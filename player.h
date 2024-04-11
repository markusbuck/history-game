#ifndef PLAYER_H
#define PLAYER_H

#include <QPoint>
#include "wall.h"
#include <box2d/box2d.h>

class Player {
public:
    Player(QPoint location, b2World* world);

    void movePlayer(int x, int y);

    // b2Body methods
    b2Vec2 getVelocity();
    void applyImpulse(b2Vec2 impulse, b2Vec2 position);
    float getMass();
    b2Vec2 getCenter();
    b2Vec2 getTopLeft();

    // state update
    enum Movement {moveLeft, moveRight, jump, stop};
    void setMoveState(Movement state);

    // physics update
    void step();

    const int width, height;
    int walkSpeed = 1000;
    int jumpPower = 200;
private:
    b2Body* body;
    Movement moveState = stop;
};

#endif // PLAYER_H
