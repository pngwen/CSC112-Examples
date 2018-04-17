// Class definition of a ball for the game of pong
#ifndef BALL_H
#define BALL_H

#include "widget.h"
#include "event.h"

class Ball : public Widget
{
public:
    //constructors
    Ball(int _x, int _y);
    Ball();

    //widget stuff
    virtual void handleEvent(Event *event);
    virtual void display();

    //velocity vector
    void vx(double _vx) { this->_vx = _vx; }
    double vx() { return this->_vx; }
    void vy(double _vy) { this->_vy = _vy; }
    double vy() { return _vy; }
    
private:
    //get time with fractional parts
    double gettime();
    
    //velocity vector
    double _vx;
    double _vy;

    //physics position
    double _px;
    double _py;

    //keep track of the last time we update
    double _lastUpdate;
};

#endif 
