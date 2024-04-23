#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include <box2D/box2D.h>
#include <functional>
#include <map>

class ContactListener : public b2ContactListener
{
public:
    ContactListener();

    using Callback = std::function<void(bool began, b2Fixture*, b2Fixture*)>;
    void BeginContact(b2Contact* contact) override;
    void EndContact(b2Contact* contact) override;

    void addCallback(b2Body* body, Callback callback);
    void removeCallback(b2Body* body);

private:
    std::map<b2Body*, Callback> callbacks;
};

#endif // CONTACTLISTENER_H
