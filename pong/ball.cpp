#include <time.h>
#include <iostream>
#include "term.h"
#include "ball.h"

using namespace std;

Ball::Ball(int _x, int _y) : Widget(_x, _y, 1, 1)
{
    //set the ball's initial position
    _vx = 0;
    _vy = 0;
    _px = _x;
    _py = _y;

    //get the current time
    _lastUpdate = gettime();
}


Ball::Ball() : Ball(40, 12)
{
    /* do nothing else */
}



//handle the event for the ball
void
Ball::handleEvent(Event *e)
{
    //ignore non timer events
    if(e->type() != "tick") return;

    //work out the elapsed time
    double current;
    double elapsed;
    current = gettime();
    elapsed = current - _lastUpdate;

    
    //update the physical position
    _px += _vx * elapsed;
    _py += _vy * elapsed;

    //erase and draw the ball
    clear();
    x(_px);
    y(_py);
    display();

    //remember our current time for the next input
    _lastUpdate = current;
}


void
Ball::display()
{
    cout << cursorPosition(x(), y()) << reverseVideo << " " << normal;
    cout.flush();
}


double
Ball::gettime()
{
    double t;
    struct timespec ts;

    clock_gettime(CLOCK_REALTIME, &ts);
    
    t = ts.tv_nsec;
    t /= 1.0e9;
    t += ts.tv_sec;

    return t;
}
