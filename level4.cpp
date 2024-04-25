#include "level4.h"

Level4::Level4(QString background) : Level(background, QPoint(10, -60)) {
    // Create levels question

    Door door(QPoint(91, -106), "What significant event followed the American victory at Saratoga in 1777?", &worldState);
    door.insertQuesionResponse("The signing of the Treaty of Paris.", false);
    door.insertQuesionResponse("The capture of Charleston, South Carolina.", false);
    door.insertQuesionResponse("The formation of the Franco-American alliance.", true);
    door.insertQuesionResponse("The commencement of negotiations in Paris.", false);
    context = "Following the American victory at Saratoga, the American diplomat Benjamin Franklin negotiated a treaty of \n alliance with France in February 1778. The Franco-American alliance brought crucial military and financial support to the American \n cause, including French troops, ships, and loans, significantly bolstering the Continental Army's capabilities. After the failure of \n the northern campaign at Saratoga, the British shifted their focus to the southern colonies, hoping to rally Loyalist support \n and gain control of strategic ports and resources. British forces, led by General Charles Cornwallis, achieved initial successes \n in the South, capturing Charleston, South Carolina, and winning several battles. Despite British advances, American forces, \n led by generals such as Nathanael Greene and Daniel Morgan, employed guerrilla warfare tactics and waged a relentless \n campaign against British supply lines and outposts. The American victories at the Battles of King's Mountain (1780) and Cowpens (1781)  \n weakened British control in the South and boosted American morale. In 1781, American and French forces, under the \n command of General George Washington and the French General Rochambeau, laid siege to the British army under General Cornwallis at \n Yorktown, Virginia. The combined American-French forces effectively trapped Cornwallis's army by land and sea, leading to the \n surrender of the British forces on October 19, 1781. Negotiations for peace began in Paris in 1782, culminating in the signing of the \nTreaty of Paris on September 3, 1783. The treaty formally ended the American Revolutionary War and recognized the independence \n of the United States of America. Britain also agreed to withdraw its troops from American soil and established the \n boundaries of the new nation.";
    door.insertHint("Look for significant \n diplomatic development \n after Saratoga.");
    door.insertHint("Consider the involvement \n of Benjamin Franklin, a key \n American diplomat.");
    door.insertHint("Focus on events that \n brought crucial military \n and financial support.");
    door.insertHint("Consider the timing \n of the event in relation \n to the overall timeline of the war.");
    doors.append(door);

    createCollisionObject(0., -111., 120., 5.);
    createCollisionObject(-1., -111., 1., 115.);
    createCollisionObject(120., -111., 1., 115.);
    createCollisionObject(0., -111., 10., 17.);
    createCollisionObject(36., -111., 7., 57.);
}

void Level4::renderCustom(QPainter *painter) {
    if (isInDialog)
        return;

    // un-mirror the text
    painter->save();
    painter->setPen(Qt::white);
    painter->setFont(QFont("Arial", 16));
    QTransform transform;
    transform.scale(1.0, -1.0);
    painter->setTransform(transform, true);

    painter->drawText(QRectF(0, 7, 338, 135), Qt::AlignCenter | Qt::TextWordWrap, "The three Americans, Adams, Franklin and Jay signed their names in alphabetical order on the treaty.");
    painter->drawText(QRectF(113, 464, 467, 77), Qt::AlignCenter | Qt::TextWordWrap, "General Cornwallis reported sick and didn't show up to the surrender.");

    painter->restore();
}
