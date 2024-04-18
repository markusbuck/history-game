#include "door.h"
#include <QDebug>
#include <QRandomGenerator>
// Door::Door(QPoint location, QPoint p1, QPoint p2, int width, QString questionText, bool isCorrect, b2World* world)
//     : location(location), questionText(questionText), isCorrect(isCorrect), hitBox(p1, p2, width, world) {
// }

Door::Door(QPoint location, Wall wall, QString questionText, bool isCorrect)
    : location(location), questionText(questionText), isCorrect(isCorrect), hitBox(wall)
{
}

void Door::insertQuesionResponse(QString text, bool isCorrect) {
    questionResponses.insert(text, isCorrect);
}


bool Door::isCorrectResponse(QString key) {
    if(questionResponses.contains(key)) {

        return questionResponses.value(key);
    }

    return false;
}

void Door::insertHint(QString hint) {
    hints.append(hint);
}

QString Door::generateHint(bool isCorrect) {

    if(isCorrect) {
        return correctText;
    }

    int randNum = QRandomGenerator::global()->bounded(4);

    return hints.at(randNum);
}
