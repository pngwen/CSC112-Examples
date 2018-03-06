// Class definition for a nifty pong paddle
#ifndef PADDLE_H
#define PADDLE_H
#include "event.h"
#include "widget.h"

const int PADDLE_HEIGHT = 3;

class Paddle : public Widget
{
public:
    Paddle() : Widget(1, 1, 1, PADDLE_HEIGHT) { /* left blank */ }
    Paddle(int _x, int _y) : Widget(_x, _y, 1, PADDLE_HEIGHT) { /* left blank */ }


    //widget overrrides
    virtual void handleEvent(Event *e) { /* do nothing */}
    virtual void display();

    //paddle methods
    virtual void paddleDown();
    virtual void paddleUp();
    
private:
};
#endif
