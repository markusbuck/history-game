#ifndef LEVEL4_H
#define LEVEL4_H

#include "level.h"

class Level4 : public Level
{
public:
    Level4(QString background);
    void renderCustom(QPainter *painter) override;
};

#endif // LEVEL3_H
