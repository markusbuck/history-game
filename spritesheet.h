#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <QString>
#include <QPainter>
/*!
 * Authors: Kevin Soto, Zak Holt, Walker Hall, Brenden Suess, and Markus Buckwalter
 * CS 3505 Assignment 9: Educational App
 * Date: 4/24/24
 *
 * Header file for the spriteSheet.
 */

class spriteSheet
{

public:
    /*!
     * \brief spriteSheet - A constructor for the spriteSheet.
     * \param fileName - The file name of the sprite.
     * \param width - The width of the sprite.
     * \param height - The height of the sprite.
     * \param mirrorVertically - A boolean to mirror the sprite vertically.
     */
    spriteSheet(QString fileName, int width, int height, bool mirrorVertically = true);

    /*!
     * \brief incrementIndex - This method will increment the index of the sprite.
     */
    void incrementIndex();

    /*!
     * \brief setIndex - This method will set the index of the sprite.
     * \param value - the value to change the index.
     */
    void setIndex(int value);

    /*!
     * \brief renderSprite - This method will render the sprite to be shown on the screen.
     * \param painter - A pointer of a painter.
     * \param target - A rectangle of the sprite.
     */
    void renderSprite(QPainter *painter, QRect target);

    /*!
     * \brief mirror - This method will mirror the sprite.
     * \param horizontal - Boolean to render the sprite horizontally.
     * \param vertical - Boolean to render the sprite vertically.
     */
    void mirror(bool horizontal, bool vertical = true);

private:
    bool mirrored;
    int width;
    int height;
    int index;
    int offsetY = 6;

    // the original is used for mirroring
    QImage original;
    QImage sprite;
};

#endif // SPRITESHEET_H
