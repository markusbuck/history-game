#include "player.h"

Player::Player(QPoint location, b2World* world)
    : width(32), height(96), movementStates() {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(location.x() + width / 2, location.y() + height / 2); // center of player
    body = world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(width / 2.0, height / 2.0); // half sizes, 4w x 12h
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
}

void Player::applyImpulse(b2Vec2 impulse, b2Vec2 position) {
    body->ApplyLinearImpulse(impulse, position, true);
}

b2Vec2 Player::getVelocity() {
    return body->GetLinearVelocity();
}

float Player::getMass() {
    return body->GetMass();
}

b2Vec2 Player::getCenter() {
    return body->GetWorldCenter();
}

b2Vec2 Player::getTopLeft() {
    return getCenter() - b2Vec2(width / 2, height / 2);
}

//

void Player::setMoveState(Movement state, bool isDown) {
    movementStates[state] = isDown;
}

//

void Player::step() {
    b2Vec2 vel = getVelocity();

    float desiredVel = 0;
    // if(body->GetLinearVelocity().y != 0)
    //     return;

    if (movementStates[Movement::keyLeft])
        desiredVel += -walkSpeed;
    if (movementStates[Movement::keyRight])
        desiredVel += walkSpeed;

    if (movementStates[Movement::jump]) {
        float jumpImpulse = getMass() * -jumpPower;
        applyImpulse(b2Vec2(0, jumpImpulse), getCenter());
        movementStates[Movement::jump] = false;
    }

    float velChange = desiredVel - vel.x;
    float impulse = getMass() * desiredVel;

    applyImpulse(b2Vec2(impulse, 0), getCenter());
}
