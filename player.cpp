#include "player.h"
#include <QDebug>

Player::Player(QPoint location, WorldState* worldState)
    : width(16), height(16), movementStates(), sprite(":/right.png", 100, 100), jumpSound() {

    jumpSound.setSource(QUrl::fromLocalFile("eaglescram.mp3"));

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.fixedRotation = true;
    bodyDef.bullet = true;
    bodyDef.linearDamping = 1.;
    bodyDef.gravityScale = 15;
    bodyDef.allowSleep = false;
    bodyDef.position.Set(location.x() + width / 2, location.y() + height / 2); // center of player
    body = worldState->world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(5 / 2.0 - .1, height/ 2.0 - .1); // half sizes, 4w x 12h
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0;
    fixtureDef.friction = 0;
    body->CreateFixture(&fixtureDef);

    dynamicBox.SetAsBox(1, 0.1, b2Vec2(0, -height / 2.0 + 0.05), 0);
    fixtureDef.isSensor = true;
    b2Fixture* foot = body->CreateFixture(&fixtureDef);
    foot->SetUserData( (void*)2 );

    worldState->worldContact->addCallback(body, [this](bool began, b2Fixture *contactFixture, b2Fixture *thisFixture) {
        unsigned long long int contactData = (unsigned long long int) contactFixture->GetUserData();
        unsigned long long int sensorData = (unsigned long long int) thisFixture->GetUserData();
        if (began){
            if(contactData == 3) {
                movementStates[Movement::keyLeft] = false;
                movementStates[Movement::keyRight] = false;

                emit onDoorContact();
            }

            // sensorData == 2 is the foot sensor to detect when on the ground
            if (sensorData == 2)
                currentContacts++;
        }
        else if (sensorData == 2)
            currentContacts--;
    });
}

void Player::applyImpulse(b2Vec2 impulse, b2Vec2 position) {
    body->ApplyLinearImpulse(impulse, position, true);
}

void Player::applyForce(b2Vec2 force) {
    body->ApplyForceToCenter(force, true);
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

void Player::step(float dt) {
    b2Vec2 vel = getVelocity();
    elapsedSinceLastFrame += dt;

    float desiredVel = 0;
    float jumpVel = 0;

    if (movementStates[Movement::keyLeft]){
        desiredVel += -walkSpeed;
        sprite.mirror(true, true);
    }
    if (movementStates[Movement::keyRight]){
        desiredVel += walkSpeed;
        sprite.mirror(false, true);
    }

    if(desiredVel == 0)
        sprite.setIndex(0);
    else if (elapsedSinceLastFrame > 0.08) {
        sprite.incrementIndex();
        elapsedSinceLastFrame = 0;
    }

    if (movementStates[Movement::jump] && currentContacts >= 1) {
        jumpVel = getMass() * jumpPower; // feels slow, especially when reaching the peak
        movementStates[Movement::jump] = false;
        jumpSound.play();
    }

    if (vel.y < 0) {
        float gravityScale = 1.0f + (-vel.y / 5.0f);
        applyForce(b2Vec2(0, -gravityScale * getMass() * 25.0f));
    }

    float velChange = desiredVel - vel.x;
    float impulse = getMass() * velChange;

    applyImpulse(b2Vec2(impulse, jumpVel), getCenter());
}
