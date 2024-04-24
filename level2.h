#ifndef LEVEL2_H
#define LEVEL2_H

#include "level.h"
/*!
 * Authors: Kevin Soto, Zak Holt, Walker Hall, Brenden Suess, and Markus Buckwalter
 * CS 3505 Assignment 9: Educational App
 * Date: 4/24/24
 *
 * Header file for the Level2 class
 */
class Level2 : public Level
{
public:
    /*!
     * \brief Level2 - Constructor for Level2.
     * \param background - The file name of the background.
     */
    Level2(QString background);

    /*!
     * \brief renderCustom - This method will render the level.
     * \param painter - The painter to draw.
     */
    void renderCustom(QPainter *painter) override;
};

#endif // LEVEL2_H
