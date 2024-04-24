#include "level2.h"

Level2::Level2(QString background) : Level(background, QPoint(10, -60)) {
    // Create levels question
    Door door(QPoint(7, -106), "George Washington was born in...", &worldState);
    door.insertQuesionResponse("March 11, 1690", false);
    door.insertQuesionResponse("April 20, 1215", false);
    door.insertQuesionResponse("February 22, 1732", true);
    door.insertQuesionResponse("December 9, 2025", false);

    door.insertHint("George Washington had no biological children.");
    door.insertHint("George Washingtons dentures\n were not made of wood.");
    door.insertHint("George Washington loved to party.");
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
