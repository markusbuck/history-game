#ifndef WORLDSTATE_H
#define WORLDSTATE_H

#include <Box2D/Box2D.h>
#include "contactlistener.h"

/*!
 * Authors: Kevin Soto, Zak Holt, Walker Hall, Brenden Suess, and Markus Buckwalter
 * CS 3505 Assignment 9: Educational App
 * Date: 4/24/24
 *
 * Header file for the world state that is part of the model.
 */
const float SCALE_FACTOR = 5.0;

struct WorldState {
    b2World* world;
    ContactListener *worldContact;
};

#endif // WORLDSTATE_H
