#include "level2.h"

Level2::Level2(QString background) : Level(background, QPoint(10, -60)) {
    // Create levels question

    Door door(QPoint(7, -106), "Which British general was defeated by American forces in the Saratoga campaign of 1777?", &worldState);
    door.insertQuesionResponse("Charles Cornwallis", false);
    door.insertQuesionResponse("John Burgoyne", true);
    door.insertQuesionResponse("William Howe", false);
    door.insertQuesionResponse("Henry Clinton", false);

    door.insertHint("Henery Clinton acted as\n commander in chief\n in America.");
    door.insertHint("William Howe acted as\n commander in chief\n in America.");
    door.insertHint("Charles Cornwallis acted as\n commander in chief\n in America.");
    door.insertHint("The last name\n ends with the letter e.");
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
    if (isInDialog)
        return;

    // un-mirror the text
    painter->save();
    painter->setPen(Qt::white);
    painter->setFont(QFont("Arial", 16));
    QTransform transform;
    transform.scale(1.0, -1.0);
    painter->setTransform(transform, true);

    painter->drawText(QRectF(30, 6, 249, 111), Qt::AlignCenter | Qt::TextWordWrap, "The British general defeated by American forces in the Saratoga campaign of 1777 was General John Burgoyne.");
    painter->drawText(QRectF(416, 12, 149, 213), Qt::AlignCenter | Qt::TextWordWrap, "He was the commander of the British army during the Saratoga campaign, which ended in the surrender of his army at the Battle of Saratoga.");
    painter->drawText(QRectF(347, 289, 218, 94), Qt::AlignCenter | Qt::TextWordWrap, " This significant American victory is often considered a turning point in the Revolutionary War, as it encouraged France to openly support the American cause.");
    painter->drawText(QRectF(32, 354, 262, 87), Qt::AlignCenter | Qt::TextWordWrap, "The first battle of the Revolutionary War took place in Lexington and Concord,");

    painter->restore();
}
