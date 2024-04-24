#ifndef LEVEL4_H
#define LEVEL4_H

#include "level.h"
/*!
 * Authors: Kevin Soto, Zak Holt, Walker Hall, Brenden Suess, and Markus Buckwalter
 * CS 3505 Assignment 9: Educational App
 * Date: 4/24/24
 *
 * Header file for the Level4 class
 */
class Level4 : public Level
{
public:
    /*!
     * \brief Level4 - Constructor for Level4.
     * \param background - The file name of the background.
     */
    Level4(QString background);

    /*!
     * \brief renderCustom - This method will render the level.
     * \param painter - The painter to draw.
     */
    void renderCustom(QPainter *painter) override;
};

#endif // LEVEL3_H
