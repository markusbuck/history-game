#include "level1.h"

Level1::Level1(QString background) : Level(background, QPoint(2, -80)) {
    // Create levels question
    Door door(QPoint(30, -30), "Where did the first battle of the Revolutionary war take place?", &worldState);
    door.insertQuesionResponse("Boston", false);
    door.insertQuesionResponse("London", false);
    door.insertQuesionResponse("Lexington and Concord", true);
    door.insertQuesionResponse("Quebec", false);

    context = "George Washington was the first president.";


    door.insertHint("It is along\n the East coast of\n America.");
    door.insertHint("The battle occured\n in what is now \ncalled the United States.");
    door.insertHint("It is in the\n Northern reigion of\n the 13 colonies.");
    door.insertHint("This battle occured\n in Massachusetts.");

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

void Level1::renderCustom(QPainter *painter) {
    if (isInDialog)
        return;

    // un-mirror the text
    painter->save();
    painter->setPen(Qt::white);
    painter->setFont(QFont("Arial", 16));
    QTransform transform;
    transform.scale(1.0, -1.0);
    painter->setTransform(transform, true);

    painter->drawText(QRectF(225, 13, 282, 100), Qt::AlignCenter | Qt::TextWordWrap, "American Revolutionary War between Great Britain and the Thirteen Colonies.");
    painter->drawText(QRectF(57, 205, 206, 138), Qt::AlignCenter | Qt::TextWordWrap, "as the Battles of Lexington and Concord, and it marked the beginning of the");
    painter->drawText(QRectF(290, 361, 264, 67), Qt::AlignCenter | Qt::TextWordWrap, "in Massachusetts, on April 19, 1775. This conflict is often referred to");
    painter->drawText(QRectF(67, 464, 372, 54), Qt::AlignCenter | Qt::TextWordWrap, "The first battle of the Revolutionary War took place in Lexington and Concord,");

    painter->restore();
}
