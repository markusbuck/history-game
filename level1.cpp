#include "level1.h"

Level1::Level1(QString background) : Level(background, QPoint(10, -60)) {
    // Create levels question
    Door door(QPoint(115, -91), "George Washington was born in...", &worldState);
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
    createCollisionObject(85., -106., 20., 5.);
    createCollisionObject(95., -101., 20., 5.);
    createCollisionObject(105., -96., 20., 5.);
}
