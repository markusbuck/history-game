#ifndef LEVEL3_H
#define LEVEL3_H

#include "level.h"

class Level3 : public Level
{
public:
    Level3(QString background);
    void renderCustom(QPainter *painter) override;
};

#endif // LEVEL3_H
