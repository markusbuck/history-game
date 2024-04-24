#ifndef LEVEL1_H
#define LEVEL1_H

#include "level.h"
/*!
 * Authors: Kevin Soto, Zak Holt, Walker Hall, Brenden Suess, and Markus Buckwalter
 * CS 3505 Assignment 9: Educational App
 * Date: 4/24/24
 *
 * Header file for the Level1 class
 */
class Level1 : public Level
{
public:
    /*!
     * \brief Level1 - Constructor for Level1.
     * \param background - The file name of the background.
     */
    Level1(QString background);

    /*!
     * \brief renderCustom - This method will render the level.
     * \param painter - The painter to draw.
     */
    void renderCustom(QPainter *painter) override;
};

#endif // LEVEL1_H
