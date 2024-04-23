#include "level.h"
#include <QDebug>

Level::Level(QString backgroundPath, QPoint spawnPosition) : collisionObjects(), background(backgroundPath) {
    // world creation
    b2Vec2 gravity(0.0f, -10.0);
    b2World *world = new b2World(gravity);
    ContactListener *worldContact = new ContactListener();
    world->SetContactListener(worldContact);

    worldState = { world, worldContact };

    // player
    player = new Player(spawnPosition, &worldState);

    //
    background.mirror(false, true);

    connect(player, &Player::onDoorContact, this, &Level::onDoorCollisionState);
}

Level::~Level() {
    delete worldState.world;
    delete player;
}

//

void Level::createCollisionObject(int x, int y, int width, int height)
{
    Wall newWall(x, y, width, height, &worldState);
    collisionObjects.push_back(newWall);
}

//

bool Level::isCorrectResponse(QString response, int doorIndex) {
    Door door = doors.at(doorIndex);
    return door.isCorrectResponse(response);
}

QString Level::generateHintResponse(QString response, int doorIndex) {
    Door door = doors.at(doorIndex);
    return door.generateHint(door.isCorrectResponse(response));
}

void Level::step() {
    if (!worldState.world || isInDialog)
        return;

    player->step(1. / 60.);
    worldState.world->Step(1.0f / 60.0f, 8, 3);
}

void Level::renderBackground(QPainter *painter) {
    painter->drawImage(QRect(0, -600, 600, 600),
                       background,
                       QRect(0, 0, 1024, 1024));
}

void Level::render(QPainter *painter) {
    // player
    player->render(painter);

    // walls
    painter->setBrush(Qt::red);
    for (const Wall& wall : collisionObjects)
        painter->drawRect(wall.x * SCALE_FACTOR, wall.y * SCALE_FACTOR, wall.width * SCALE_FACTOR, wall.height * SCALE_FACTOR);

    // door
    painter->setBrush(Qt::green);
    Door door = doors.at(0);

    b2Vec2 doorPosition = SCALE_FACTOR * door.getTopLeft();
    painter->drawRect(doorPosition.x, doorPosition.y, door.width * SCALE_FACTOR, door.height * SCALE_FACTOR);
}

void Level::onDoorCollisionState() {
    isInDialog = true;
    QString doorQuestionText = doors.at(0).questionText;

    QHash<QString, bool> questionResponses = doors.at(0).questionResponses;
    qDebug() << "onDoorCollisionState";

    emit generateQuestionnaire(doorQuestionText, questionResponses);
}


void Level::isInputCorrect(QString response) {
    bool isCorrect = isCorrectResponse(response, 0);
    QString messagePopUp = generateHintResponse(response, 0);

    qDebug() << "isInputCorrect" << isCorrect;

    emit displayPopUp(isCorrect, messagePopUp);
}

void Level::exitDialog() {
    isInDialog = false;
}
