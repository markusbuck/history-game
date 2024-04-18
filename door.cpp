#include "door.h"
#include <QDebug>
#include <QRandomGenerator>
// Door::Door(QPoint location, QPoint p1, QPoint p2, int width, QString questionText, bool isCorrect, b2World* world)
//     : location(location), questionText(questionText), isCorrect(isCorrect), hitBox(p1, p2, width, world) {
// }

Door::Door(QPoint location, Wall wall, QString questionText, WorldState* worldState)
    : location(location), questionText(questionText), isCorrect(isCorrect), hitBox(wall)
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(location.x() + width / 2, location.y() + height / 2); // center of player
    body = worldState->world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(width / 2.0 - .1, height / 2.0 - .1); // half sizes, 4w x 12h
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

    worldState->worldContact->addCallback(body, [this](bool began, b2Fixture *fixture) {
        if (began)
            currentContacts++;
        else
            currentContacts--;
    });

}

void Door::insertQuesionResponse(QString text, bool isCorrect) {
    questionResponses.insert(text, isCorrect);
}

b2Vec2 Door::getTopLeft() {
    return body->GetWorldCenter() - b2Vec2(width / 2, height / 2);
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
