#include "level3.h"

Level3::Level3(QString background) : Level(background, QPoint(10, -60)) {
    // Create levels question

    Door door(QPoint(91, -106), "What was the British strategy in 1777 to deal with the rebellious American colonies?", &worldState);
    door.insertQuesionResponse("Dividing the colonies \n with a three-pronged \n military campaign.", true);
    door.insertQuesionResponse("Launching a direct \n assault on Philadelphia.", false);
    door.insertQuesionResponse("Negotiating a peace\n treaty with \n American leaders.", false);
    door.insertQuesionResponse("Withdrawing British \n forces to Canada.", false);
    context = "After the battle of Lexington and Concord word of the battle spread throughout all of the colonies and heightened the propaganda\nsurrounding the revolution. However, despite the propaganda most colonists were not seeking independence rather \n just a larger measure of self-government within the British Empire. This would change throughout the development of the revolution.\n  After the battle congress convened for the second time in May 1775. This convention was intended to allow the \ncolonies to plan their next course of action against Britain. In June of 1775, the battle of Bunker Hill took place this battle was a \n continuation of the last altercation in Concord. British forces had been besieged in Boston by the colonial militia they sought to take\n  Boston back. The American forces decided to fortify Breeds Hill to prevent the British from occupying it. Although initially, the \n  British assaults were not successful on the third assault the British broke through and occupied Breeds Hill despite suffering heavy \n casualties. The Americans were forced to retreat, the British casualties numbered roughly 1000 and the Americans numbered \n around 450. Although the American forces were defeated, due to the casualties they inflicted, the British were forced to take this \n matter more seriously. June 7, 1776, Richard Henry Lee suggested that the Americans declare independence from Britain. \n Congress appoints a committee to write the formal document declaring independence. While composing the document \n serious debates were made regarding slavery. Representatives of the slaveholding South had different ideals than the North \n regarding this issue. This issue would later manifest into the Civil War, but at the time the colonies needed to unite against the British \n to stand a chance. After a stalemate between the two distinct sides, the clause is dropped. On July 4, 1776, the Declaration of \n Independence was formed. This served the purpose of asserting the natural rights of the colonies, indictment of British tyranny and \n  oppression, inspiration for Democracy and self-governance, and a rallying cry for unity amongst the colonies. Another big idea of \n the Declaration of Independence was to gain the favor of the French.";
    door.insertHint("Focus on British \n military strategy \n described in the background context.");
    door.insertHint("Consider the significance \n of the Battle of saratoga \n and its impact on \n British strategy.");
    door.insertHint("Focus on events leading up to \n Burgoyne's surrender and \n how it impacted the British.");
    door.insertHint("Consider the position \n of the British \n at this time.");
    doors.append(door);

    createCollisionObject(0., -111., 120., 5.);
    createCollisionObject(-1., -111., 1., 115.);
    createCollisionObject(120., -111., 1., 115.);
    createCollisionObject(0., -111., 10., 17.);
    createCollisionObject(36., -111., 7., 57.);
}

void Level3::renderCustom(QPainter *painter) {
    if (isInDialog)
        return;

    // un-mirror the text
    painter->save();
    painter->setPen(Qt::white);
    painter->setFont(QFont("Arial", 16));
    QTransform transform;
    transform.scale(1.0, -1.0);
    painter->setTransform(transform, true);

    painter->drawText(QRectF(14, 27, 230, 207), Qt::AlignCenter | Qt::TextWordWrap, "The battlegrounds of Saratoga is now a national park.");
    painter->drawText(QRectF(325, 396, 183, 79), Qt::AlignCenter | Qt::TextWordWrap, "Benjamin Franklin was a diplomat.");

    painter->restore();
}
