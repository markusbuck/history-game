#include "player.h"
#include <QDebug>

Player::Player(QPoint location, WorldState* worldState)
    : width(16), height(16), movementStates(), sprite(":/right.png", 100, 100) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.fixedRotation = true;
    bodyDef.bullet = true;
    bodyDef.linearDamping = 1.;
    bodyDef.gravityScale = 6;
    bodyDef.position.Set(location.x() + width / 2, location.y() + height / 2); // center of player
    body = worldState->world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(5 / 2.0 - .1, height/ 2.0 - .1); // half sizes, 4w x 12h
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    b2Fixture* fixture = body->CreateFixture(&fixtureDef);
    fixture->SetRestitution(0);
    worldState->worldContact->addCallback(body, [this](bool began, b2Fixture *fixture) {
        unsigned long long int data = (unsigned long long int) fixture->GetUserData();
        if (began){
            if(data == 3) {
                qDebug() << data;

                movementStates[Movement::keyLeft] = false;
                movementStates[Movement::keyRight] = false;

                emit onDoorContact();
            }
            currentContacts++;
        }
        else
            currentContacts--;
    });
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

void Player::render(QPainter *painter){
    b2Vec2 playerPosition = SCALE_FACTOR * getTopLeft();
    sprite.renderSprite(painter, QRect(playerPosition.x, playerPosition.y, width * SCALE_FACTOR, height * SCALE_FACTOR));
}

//

void Player::step() {
    b2Vec2 vel = getVelocity();

    float desiredVel = 0;
    float jumpVel = 0;

    if (movementStates[Movement::keyLeft]){
        desiredVel += -walkSpeed;
        sprite.mirror(true, true);
        sprite.incrementIndex();
    }
    if (movementStates[Movement::keyRight]){
        desiredVel += walkSpeed;
        sprite.mirror(false, true);
        sprite.incrementIndex();
    }

    if(desiredVel == 0)
        sprite.setIndex(0);

    if (movementStates[Movement::jump] && currentContacts >= 1) {
        jumpVel = getMass() * jumpPower;
        movementStates[Movement::jump] = false;
    }

    float velChange = desiredVel - vel.x;
    float impulse = getMass() * velChange;

    applyImpulse(b2Vec2(impulse, jumpVel), getCenter());
}
