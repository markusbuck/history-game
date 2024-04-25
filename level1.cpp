#include "level1.h"

Level1::Level1(QString background) : Level(background, QPoint(2, -80)) {
    // Create levels question
    Door door(QPoint(30, -30), "Which of the following is not the main catalyst to the revolution?", &worldState);
    door.insertQuesionResponse("Boston Tea Party", false);
    door.insertQuesionResponse("Stamp Act", false);
    door.insertQuesionResponse("Lexington and Concord", false);
    door.insertQuesionResponse("The Currency Act", true);

    context = "This box is meant to offer help give information/insights into the event and answer questions.\n To understand the Revolutionary War it is necessary to first understand why it occurred. The British's original\n intentions for the colonies were to expand their territory and gain more resources. These territories would be\n thought of as an extension of their own and in no way an independent entity. Since the British provided\n protection and resources to the colonies many colonists accepted the British rule. This time is called\n the early colonial period(1607-1760's), this marked a hard and desperate time for many colonists\n settling into new territory. However, once the colonies did start to settle, some colonists opposed\n British rule, two notable figureheads Sam Adams and John Handcock thought British rule was not beneficial\n to themselves and the colonies. They believed British rule restricted freedom/power, personal rights, and the\n liberty of personal finances. The British taxing was the main point in question. Specifically, the idea of taxing the\n colonies without the colonies having authority over it. One act specifically that was a catalyst to the revolution was\nthe Stamp Act in March of 1765. This act was imposed on the colonies to recoup from the massive debt incurred from\n the war with the French. This taxed a wide range of transactions inside all of the colonies. Colonists resented\n having to pay taxes on goods bought and sold from the British. This caused a huge uproar and caused many riots\n which led to taxes not being collected. In response to this, the British started the Townshend Acts, British\n parliament attempted to assert authority over the colonists again by taxing goods imported from Great Britain. The\n colonists retorted by boycotting British goods. The British sent troops to occupy Boston, this increased tensions\nbetween the two. Another key event that led to the conflict is the Boston Massacre this event \n a total of 3 people died and two others were mortally wounded. An influential colonial figure Paul Revere used\nthis as an opportunity to produce propaganda against the British and gain colonists favor over the\nrevolution. The colonist leaders used this momentum to procure a protest, this protest was called The Boston\n Tea Party. The British then decided to close the Boston harbor until the colonists had paid for all of the \ntea they dumped in full. This was known as The Coercive Acts in March 1774, this of course further\nangered the colonists and caused them to all convene in what is known as the first continental\ncongress. This meeting’s purpose was to resist the acts imposed and to further define American\nrights. The British, perturbed by the colonists acts of disobedience, decided to resort to violence\nto resolve the issues by force. This event became known as the battle of Lexington and \nConcord. On the night of April 18, 1775 British troops under the command of lieutenant \nColonel Francis Smith were dispatched from Boston to march to Concord and seize \nthe munitions that the colonists have been gathering in resistance to British rule. \nThe colonists were well prepared for this confrontation ahead of time due to the\nintelligence they received. The colonists successfully fended off the British inflicting\nserious casualties and causing the British to retreat. This marked the start of Americas \n war for independence.";


    door.insertHint("Consider what\nndirectly impacted the\n revolution.");
    door.insertHint("Be weary of\n events that imposed\n punitive measures.");
    door.insertHint("Is is not synonymous\n to taxation without\n representation.");
    door.insertHint("Make note of\n events that escalated\n tensions between colonies\n and Britian.");

    doors.append(door);

    createCollisionObject(0., -111., 100., 5.);
    createCollisionObject(-1., -111., 1., 115.);
    createCollisionObject(90., -109., 40., 10.);
    createCollisionObject(30., -90., 50., 2.);
    createCollisionObject(30., -87., 20., 10.);
    createCollisionObject(60., -69., 20., 5.);
    createCollisionObject(80., -69., 5., 10.);
    createCollisionObject(80., -59., 20., 5.);
    createCollisionObject(105., -48., 20., 5.);
    createCollisionObject(30., -35., 60., 5.);
    createCollisionObject(120., -111., 1., 115.);
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

    painter->drawText(QRectF(225, 13, 282, 100), Qt::AlignCenter | Qt::TextWordWrap, "In the Battle of Concord 73 Brittish soldiers died.");
    painter->drawText(QRectF(290, 361, 264, 67), Qt::AlignCenter | Qt::TextWordWrap, "Paul Revere warned the colonists about the Brittish coming to Concord.");
    painter->drawText(QRectF(67, 464, 372, 54), Qt::AlignCenter | Qt::TextWordWrap, "The colonists destroyed over 92,000 pounds of British tea.");

    painter->restore();
}
