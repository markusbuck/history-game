#include "door.h"

Door::Door(QPoint location, QPoint p1, QPoint p2, int width, QString questionText, bool isCorrect){
    this->location = location;
    this->questionText = questionText;
    this->isCorrect = isCorrect;

    this->hitBox = Wall(p1, p2, width);
}

Door::Door(QPoint location, Wall wall, QString questionText, bool isCorrect) {
    this->location = location;
    this->questionText = questionText;
    this->isCorrect = isCorrect;

    this->hitBox = wall;
}
