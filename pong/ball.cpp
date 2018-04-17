#include <time.h>
#include "ball.h"

Ball::Ball(int _x, int _y) : Widget(_x, _y, 1, 1)
{
    //set the ball's initial position
    _vx = 0;
    _vy = 0;
    _px = _x;
    _py = _y;

    //get the current time
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    _lastUpdate = ts.tv_nsec;
}


Ball::Ball() : Ball(40, 12)
{
    /* do nothing else */
}



//handle the event for the ball
void
Ball:handleEvent(Event *e)
{
    //ignore non timer events
    if(e->type() != "tick") return;

    //work out the elapsed time
    double current;
    double elapsed;
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    current = ts.tv_nsec;
    current /= 1.0e9;
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
