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

    createCollisionObject(0., -111., 120., 5.);
    createCollisionObject(0., -111., 5., 115.);


    createCollisionObject(29., -107., 20., 13.);

    // New level

    createCollisionObject(66., -20., 13., 4.);

    createCollisionObject(0., -70., 30., 5.);
    createCollisionObject(25., -70., 5., 10.);
    createCollisionObject(25., -59., 30., 5.);
    createCollisionObject(40., -54., 64., 5.);
    createCollisionObject(60., -49., 19., 10.);

    createCollisionObject(0., -30., 52., 4.);
    createCollisionObject(72., -50., 7., 30.);

    createCollisionObject(85., -82., 30., 4.);

    createCollisionObject(60., -83., 7., 30.);
    createCollisionObject(60., -90., 12., 6.);


    createCollisionObject(115., -111., 5., 115.);
}

void Level2::renderCustom(QPainter *painter) {

}
