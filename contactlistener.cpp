#include "contactlistener.h"

ContactListener::ContactListener() : callbacks() {}

void ContactListener::BeginContact(b2Contact* contact) {
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    // the first fixture supplied is the fixture that contacted the body
    // the second fixture supplied is the fixture of the body

    b2Body *bodyA = fixtureA->GetBody();
    if (callbacks.find(bodyA) != callbacks.end())
        callbacks[bodyA](true, fixtureB, fixtureA);

    b2Body *bodyB = fixtureB->GetBody();
    if (callbacks.find(bodyB) != callbacks.end())
        callbacks[bodyB](true, fixtureA, fixtureB);
}
void ContactListener::EndContact(b2Contact* contact) {
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    // the first fixture supplied is the fixture that contacted the body
    // the second fixture supplied is the fixture of the body

    b2Body *bodyA = fixtureA->GetBody();
    if (callbacks.find(bodyA) != callbacks.end())
        callbacks[bodyA](false, fixtureB, fixtureA);

    b2Body *bodyB = fixtureB->GetBody();
    if (callbacks.find(bodyB) != callbacks.end())
        callbacks[bodyB](false, fixtureA, fixtureB);
}

void ContactListener::addCallback(b2Body* body, Callback callback) {
    callbacks[body] = callback;
}

void ContactListener::removeCallback(b2Body* body) {
    callbacks.erase(body);
}
