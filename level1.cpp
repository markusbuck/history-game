#include "level1.h"

Level1::Level1(QString background) : Level(background, QPoint(10, -60)) {
    // Create levels question
    Door door(QPoint(30, -30), "Where did the first battle of the Revolutionary war take place?", &worldState);
    door.insertQuesionResponse("Boston", false);
    door.insertQuesionResponse("London", false);
    door.insertQuesionResponse("Lexington and Concord", true);
    door.insertQuesionResponse("Quebec", false);

    door.insertHint("George Washington had\n no biological\n children.");
    door.insertHint("George Washingtons\n dentures were\n not made of wood.");
    door.insertHint("George Washington loved\n to party.");
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
