#ifndef WALL_H
#define WALL_H

#include <QPoint>
#include <box2d/box2d.h>
#include "WorldState.h"

/*!
 * Authors: Kevin Soto, Zak Holt, Walker Hall, Brenden Suess, and Markus Buckwalter
 * CS 3505 Assignment 9: Educational App
 * Date: 4/24/24
 *
 * Header file for the wall that is part of a level.
 */
class Wall {

public:
    /*!
     * \brief Wall - Constructor for the wall.
     * \param x - The x-coordinate of the wall.
     * \param y - The y-coordinate of the wall.
     * \param w - The width of the wall.
     * \param h - The height of the wall.
     * \param worldState - A pointer of the world state.
     */
    Wall(float x, float y, float w, float h, WorldState* worldState);

    float x, y;
    float width, height;
};

#endif // WALL_H
