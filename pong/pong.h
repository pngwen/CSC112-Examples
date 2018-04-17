// Class definition of the pong game
#ifndef PONG_H
#define PONG_H

#include "widget.h"
#include "event.h"
#include "timer.h"

class Pong : public Widget
{
public:
    Pong(int _x, int _y);
    Pong();

    //event handling
    virtual void handleEvent(Event *e);

    //drawing functions
    virtual void display();
    
private:
    Timer t;
};

#endif
