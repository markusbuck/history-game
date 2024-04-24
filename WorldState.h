#ifndef WORLDSTATE_H
#define WORLDSTATE_H

#include <Box2D/Box2D.h>
#include "contactlistener.h"

const float SCALE_FACTOR = 5.0;

struct WorldState {
    b2World* world;
    ContactListener *worldContact;
};

#endif // WORLDSTATE_H
