#include "level1.h"

Level1::Level1(QString background) : Level(background, QPoint(10, -60)) {
    // Create levels question
    Door door(QPoint(30, -30), "George Washington was born in...", &worldState);
    door.insertQuesionResponse("March 11, 1690", false);
    door.insertQuesionResponse("April 20, 1215", false);
    door.insertQuesionResponse("February 22, 1732", true);
    door.insertQuesionResponse("December 9, 2025", false);

    door.insertHint("George Washington had no biological children.");
    door.insertHint("George Washingtons dentures\n were not made of wood.");
    door.insertHint("George Washington loved to party.");
    door.insertHint("Hint 4");
    doors.append(door);

    createCollisionObject(0., -111., 100., 5.);
    createCollisionObject(0., -111., 5., 115.);

    createCollisionObject(90., -109., 40., 10.);

    createCollisionObject(30., -90., 50., 2.);
    //createCollisionObject(30., -90., 5., 50.);
    createCollisionObject(30., -87., 20., 10.);

    createCollisionObject(60., -69., 20., 5.);
    createCollisionObject(80., -69., 5., 10.);
    createCollisionObject(80., -59., 20., 5.);

    createCollisionObject(105., -48., 20., 5.);
    createCollisionObject(30., -35., 60., 5.);

    createCollisionObject(115., -111., 5., 115.);
}
