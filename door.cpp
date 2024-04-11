#include "door.h"

// Door::Door(QPoint location, QPoint p1, QPoint p2, int width, QString questionText, bool isCorrect, b2World* world)
//     : location(location), questionText(questionText), isCorrect(isCorrect), hitBox(p1, p2, width, world) {
// }

Door::Door(QPoint location, Wall wall, QString questionText, bool isCorrect)
    : location(location), questionText(questionText), isCorrect(isCorrect), hitBox(wall)
{
}
