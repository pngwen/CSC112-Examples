// This an abstract class meant to represent an event.
// The base class effectively does nothing, but does provide
// a mechansim to get a string event type.
#ifndef EVENT_H
#define EVENT_H
#include<string>
class Event
{
public:
    virtual std::string type()=0;
};
#endif
