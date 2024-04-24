#include "level2.h"

Level2::Level2(QString background) : Level(background, QPoint(10, -60)) {
    // Create levels question
    Door door(QPoint(115, -91), "Which British general was defeated by American forces in the Saratoga campaign of 1777?", &worldState);
    door.insertQuesionResponse("Charles Cornwallis", false);
    door.insertQuesionResponse("John Burgoyne", true);
    door.insertQuesionResponse("William Howe", false);
    door.insertQuesionResponse("Henry Clinton", false);

    door.insertHint("George Washington had\n no biological\n children.");
    door.insertHint("George Washingtons\n dentures were\n not made of wood.");
    door.insertHint("George Washington loved\n to party.");
    door.insertHint("Hint 4");
    doors.append(door);

    createCollisionObject(0., -111., 100., 5.);
    createCollisionObject(85., -106., 20., 5.);
    createCollisionObject(95., -101., 20., 5.);
    createCollisionObject(105., -96., 20., 5.);
    createCollisionObject(30., -85., 50., 5.);
}

void Level2::renderCustom(QPainter *painter) {

}
