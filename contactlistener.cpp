#include "contactlistener.h"

ContactListener::ContactListener() : callbacks() {}

void ContactListener::BeginContact(b2Contact* contact) {
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    b2Body *bodyA = fixtureA->GetBody();
    if (callbacks.find(bodyA) != callbacks.end())
        callbacks[bodyA](true, fixtureB);

    b2Body *bodyB = fixtureB->GetBody();
    if (callbacks.find(bodyB) != callbacks.end())
        callbacks[bodyB](true, fixtureA);
}
void ContactListener::EndContact(b2Contact* contact) {
    b2Fixture* fixtureA = contact->GetFixtureA();
    b2Fixture* fixtureB = contact->GetFixtureB();

    b2Body *bodyA = fixtureA->GetBody();
    if (callbacks.find(bodyA) != callbacks.end())
        callbacks[bodyA](false, fixtureB);

    b2Body *bodyB = fixtureB->GetBody();
    if (callbacks.find(bodyB) != callbacks.end())
        callbacks[bodyB](false, fixtureA);
}

void ContactListener::addCallback(b2Body* body, Callback callback) {
    callbacks[body] = callback;
}

void ContactListener::removeCallback(b2Body* body) {
    callbacks.erase(body);
}
