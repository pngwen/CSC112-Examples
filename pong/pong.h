// Class definition of the pong game
#ifndef PONG_H
#define PONG_H

#include "widget.h"
#include "event.h"
#include "timer.h"
#include "ball.h"
#include "paddle.h"
#include "bigNumber.h"

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
    void computerMove();
    void bounce();
    bool playerScore();
    bool computerScore();
    
    Timer t;
    Ball ball;
    Paddle player;
    Paddle computer;
    int playerPoints;
    int computerPoints;
    BigNumber pnum;
    BigNumber cnum;
};

#endif
