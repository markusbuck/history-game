#include "spritesheet.h"
#include <QImage>

spriteSheet::spriteSheet(QString fileName, int width, int height, bool mirrorVertically):
    sprite(fileName),
    original(fileName),
    width(width),
    height(height),
    index(0){

    sprite.mirror(false, mirrorVertically);
    mirrored = false;
}

void spriteSheet::incrementIndex(){
    if((index + 1) * width >= sprite.width())
        index = -1;
    index++;
}

void spriteSheet::setIndex(int value){
    index = value;
}

void spriteSheet::renderSprite(QPainter *painter, QRect target){
    if(mirrored) {
        painter->drawImage(target,
            sprite,
            QRect((sprite.width() - (index + 1) * width), offsetY, width, height));
    }
    else {
        painter->drawImage(target,
            sprite,
            QRect(index * width, offsetY, width, height));
    }
}

void spriteSheet::mirror(bool horizontal, bool vertical){
    if (mirrored == horizontal)
        return;
    sprite = original.copy();
    sprite.mirror(horizontal, vertical);
    mirrored = horizontal;
}



