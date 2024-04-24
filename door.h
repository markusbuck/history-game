#ifndef DOOR_H
#define DOOR_H

#include "wall.h"
#include <QString>
#include <box2d/box2d.h>
#include <QHash>
/*!
 * Authors: Kevin Soto, Zak Holt, Walker Hall, Brenden Suess, and Markus Buckwalter
 * CS 3505 Assignment 9: Educational App
 * Date: 4/24/24
 *
 * Header file for the door that is part of a level.
 */
class Door {
private:
    QPoint location;
    bool isCorrect;

    b2Body* body;
public:
    /*!
     * \brief Door - A constructor for the door.
     * \param location - The location of the door in a level.
     * \param questionText - The text of the question.
     * \param worldState - The world state.
     */
    Door(QPoint location, QString questionText, WorldState* worldState);
    // Door(QPoint location, QPoint point, QPoint point2, int width, QString questionText, bool isCorrect, b2World* world);

    /*!
     * \brief insertQuesionResponse - This method will add a response, and a bool to determine if it's correct.
     * \param text - The text of the response.
     * \param isCorrect - A bool to determine if it's correct.
     */
    void insertQuesionResponse(QString text, bool isCorrect);

    /*!
     * \brief insertHint - This method will add a hint to help guide the user on an incorrect choice.
     * \param hint - The text of the hint.
     */
    void insertHint(QString hint);

    /*!
     * \brief isCorrectResponse - This method will check if the given text is a correct response.
     * \param key - The text of the response.
     * \return True if the response is correct, false otherwise.
     */
    bool isCorrectResponse(QString key);

    QString questionText;
    QHash<QString, bool> questionResponses;
    QList<QString> hints;

    /*!
     * \brief generateHint - This method will randomly select a hint to guide the user to the correct answer.
     * \param isCorrect - A boolean to determine which hint to return.
     * \return A text that will guide the user.
     */
    QString generateHint(bool isCorrect);
    QString correctText;
    int width = 8, height = 16;

    int currentContacts = 0;

    /*!
     * \brief getTopLeft - This method will get the top left of the door.
     * \return a b2Vec2 of the door.
     */
    b2Vec2 getTopLeft();
};

#endif // DOOR_H
