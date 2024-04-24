#ifndef LEVEL3_H
#define LEVEL3_H

#include "level.h"
/*!
 * Authors: Kevin Soto, Zak Holt, Walker Hall, Brenden Suess, and Markus Buckwalter
 * CS 3505 Assignment 9: Educational App
 * Date: 4/24/24
 *
 * Header file for the Level3 class
 */
class Level3 : public Level
{
public:
    /*!
     * \brief Level3 - Constructor for Level3.
     * \param background - The file name of the background.
     */
    Level3(QString background);

    /*!
     * \brief renderCustom - This method will render the level.
     * \param painter - The painter.
     */
    void renderCustom(QPainter *painter) override;
};

#endif // LEVEL3_H
