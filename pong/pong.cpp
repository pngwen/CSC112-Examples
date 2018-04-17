#include <iostream>
#include <string>
#include "pong.h"
#include "term.h"

using namespace std;

//constructors
Pong::Pong(int _x, int _y) : Widget(_x, _y, 80, 24)
{
    //set the delay and start the timer
    t.delay(1);
    t.receiver(this);
    t.start();
}
Pong::Pong() : Pong(1, 1) { /* nothing to see here */ }



void
Pong::handleEvent(Event *e)
{
    //handle tick events
    if(e->type() == "tick") {
	//time to update the frame
	cout << "TICK" << endl;
    }

    //handle keyboard events
    if(e->type() == "keyboard") {
	//we got a keyboard event!
	cout << "KEYPRESS" << endl;
    }
}



void
Pong::display()
{
}
