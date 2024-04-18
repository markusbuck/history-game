#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <QString>
#include <QPainter>

class spriteSheet
{

public:
    spriteSheet(QString fileName, int width, int height, bool mirrorVertically = true);

    void incrementIndex();
    void setIndex(int value);
    void renderSprite(QPainter *painter, QRect target);
    void mirror(bool horizontal, bool vertical = true);

private:
    bool mirrored;
    int width;
    int height;
    int index;
    int offsetY = 6;

    QImage original;
    QImage sprite;
};

#endif // SPRITESHEET_H
