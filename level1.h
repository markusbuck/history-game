#ifndef LEVEL1_H
#define LEVEL1_H

#include "level.h"

class Level1 : public Level
{
public:
    Level1(QString background);
    void renderCustom(QPainter *painter) override;
};

#endif // LEVEL1_H
