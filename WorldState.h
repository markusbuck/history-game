#ifndef WORLDSTATE_H
#define WORLDSTATE_H

#include <box2D/box2D.h>
#include "contactlistener.h"

struct WorldState {
    b2World* world;
    ContactListener *worldContact;
};

#endif // WORLDSTATE_H
