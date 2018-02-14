//Point implementation
#include "point.h"
#include "term.h"
#include <iostream>

using namespace std;

Point::Point()
{
    _complete = false;
}


void Point::display()
{
    cout << cursorPosition(x(), y()) << "*";
}


void Point::handleEvent(Event *e)
{
    //do nothing!
}



bool Point::isComplete()
{
    return _complete;
}

void Point::addPoint(int _x, int _y)
{
    //set the widget position
    x(_x);
    y(_y);

    //we're done!
    _complete = true;
}
