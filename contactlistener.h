#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include <Box2D/Box2D.h>
#include <functional>
#include <map>
/*!
 * Authors: Kevin Soto, Zak Holt, Walker Hall, Brenden Suess, and Markus Buckwalter
 * CS 3505 Assignment 9: Educational App
 * Date: 4/24/24
 *
 * Header file for the ContactListener.
 */
class ContactListener : public b2ContactListener
{
public:
    /*!
     * \brief ContactListener - Constructor for ContactListener.
     */
    ContactListener();

    using Callback = std::function<void(bool began, b2Fixture*, b2Fixture*)>;

    /*!
     * \brief BeginContact - This method will add a callback to the object being hit.
     * \param contact - The object being in contact.
     */
    void BeginContact(b2Contact* contact) override;

    /*!
     * \brief EndContact - This method will remove a callback on the contact.
     * \param contact - The object leaving contact.
     */
    void EndContact(b2Contact* contact) override;

    /*!
     * \brief addCallback - This method will add a callback to the hashtable of callbacks.
     * \param body - The key of the body.
     * \param callback - The value of the callback.
     */
    void addCallback(b2Body* body, Callback callback);

    /*!
     * \brief removeCallback - This method will remove a callback on the hashtable of callbacks.
     * \param body - The key to remove.
     */
    void removeCallback(b2Body* body);

private:
    std::map<b2Body*, Callback> callbacks;
};

#endif // CONTACTLISTENER_H
