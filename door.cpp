#include "door.h"

#include <QDebug>
#include <QRandomGenerator>

Door::Door(QPoint location, QString questionText, WorldState* worldState)
    : location(location), questionText(questionText)
{
    // create the door static body
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(location.x() + width / 2, location.y() + height / 2); // center of door
    body = worldState->world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(width / 2.0 - .1, height / 2.0 - .1); // half sizes, 4w x 12h
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.isSensor = true;
    b2Fixture* fixture = body->CreateFixture(&fixtureDef);
    // door id is 3
    fixture->SetUserData((void*)3);
}

void Door::insertQuesionResponse(QString text, bool isCorrect) {
    questionResponses.insert(text, isCorrect);
}

b2Vec2 Door::getTopLeft() {
    return body->GetWorldCenter() - b2Vec2(width / 2, height / 2);
}


bool Door::isCorrectResponse(QString key) {
    if(questionResponses.contains(key))
        return questionResponses.value(key);

    return false;
}

void Door::insertHint(QString hint) {
    hints.append(hint);
}

QString Door::generateHint(bool isCorrect) {
    if(isCorrect)
        return correctText;

    int randNum = QRandomGenerator::global()->bounded(4);
    return hints.at(randNum);
}
