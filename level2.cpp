#include "level2.h"

Level2::Level2(QString background) : Level(background, QPoint(10, -60)) {
    // Create levels question
    Door door(QPoint(7, -106), "Which of the following motivations behind the Declaration of Independence?", &worldState);
    door.insertQuesionResponse("Alliance with French", true);
    door.insertQuesionResponse("Personal Enmity", false);
    door.insertQuesionResponse("Religious Conflict", false);
    door.insertQuesionResponse("Economic Gain", false);
    context = "After the battle of Lexington and Concord word of the battle spread throughout all of the colonies and heighted\n the propaganda surrounding the revolution. However, despite the propaganda most colonists were not\nseeking independence rather just a larger measure of self-government within the British Empire. This\nwould change throughout the development of the revolution.  After the battle congress convened for the second time\nin May 1775. This convention was intended to allow the colonies to plan their next course of action against\nBritian. In June of 1775 the battle of bunker hill took place this battle was a continuation of the last altercation\n in Concord. British forces had been besieged in Boston by the colonial militia they sought to take Boston back.\n The American forces decided to fortify Breeds hill to prevent the British from occupying it. Although initially the \n British assaults were not successful on the third assault the British broke through and occupied Breeds hill despite\n suffering heavy casualties. The Americans were forced to retreat, the British casualties numbered roughly 1000\nand the American numbered around 450. Although, the American forces were defeated, due to the casualties they \n inflicted, the British were forced to take this matter more seriously. June 7, 1776, Richard Henery Lee suggests that the\n Americans declare independence from Britian. Congress appoints a committee to write the formal document declaring\n independence. In the midst of composing the document serious debates were made regarding slavery. Representatives\nof the slaveholding South had different ideals than the North regarding this issue. This issue would later manifest into the\nCivil War, but at the time the colonies needed to unite against the British to stand a chance. After a stalemate between the \ntwo distinct sides the clause is dropped. In July 4, 1776 the Declaration of Independence was formed. This served the purpose\n of asserting the natural rights of the colonies, indictment of British tyranny and oppression, inspiration for Democracy and self \ngovernance and a rallying cry for unity amongst the colonies. Another big idea of the declaration of independence was to gain favor\n of the French.";
    door.insertHint("Focus on motivations\n that align with strategic\n diplomatic goals.");
    door.insertHint("Consider international support.");
    door.insertHint("Disregard personal\n or domestic concerns.");
    door.insertHint("Consider support needed\n to fend off Britian.");
    doors.append(door);
    createCollisionObject(0., -111., 120., 5.);
    createCollisionObject(-1., -111., 1., 115.);
    createCollisionObject(29., -107., 20., 13.);
    createCollisionObject(66., -20., 13., 4.);
    createCollisionObject(0., -70., 30., 5.);
    createCollisionObject(25., -70., 5., 10.);
    createCollisionObject(25., -59., 30., 5.);
    createCollisionObject(40., -54., 64., 5.);
    createCollisionObject(60., -49., 19., 10.);
    createCollisionObject(0., -30., 52., 4.);
    createCollisionObject(72., -50., 7., 30.);
    createCollisionObject(85., -82., 35., 4.);
    createCollisionObject(60., -83., 7., 30.);
    createCollisionObject(60., -90., 12., 6.);
    createCollisionObject(120., -111., 1., 115.);
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
    painter->drawText(QRectF(30, 6, 249, 111), Qt::AlignCenter | Qt::TextWordWrap, "In the second Continential congress meeting George Washington was appointed Commander in chief.");
    painter->drawText(QRectF(416, 12, 149, 213), Qt::AlignCenter | Qt::TextWordWrap, "The draft of the Declaration of Independence underwent 86 changes before its final version.");
    painter->drawText(QRectF(347, 289, 218, 94), Qt::AlignCenter | Qt::TextWordWrap, "Eight signers of the Declaration of Independence were born in Britian.");
    painter->restore();
}
