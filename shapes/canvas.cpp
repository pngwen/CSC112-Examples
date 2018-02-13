// A widget which paints a canvas on the screen.  This canvas will allow us
// to draw shapes in the terminal window.
#include <iostream>
#include "canvas.h"
#include "term.h"

using namespace std;

//constructors
Canvas::Canvas()
{
    x(1);
    y(1);
    this->cx = 1;
    this->cy = 1;
}


//required widget function
void 
Canvas::display()
{
    cout << cursorPosition(cx, cy) << '+';
    cout.flush();
}


void 
Canvas::handleEvent(Event *e)
{
    KeyboardEvent *kb;

    if(e->type() == "keyboard") {
        kb = (KeyboardEvent*) e;
        switch(kb->key()) {
        case UP:
            cursorUp();
            break;
        case DOWN:
            cursorDown();
            break;
        case LEFT:
            cursorLeft();
            break;
        case RIGHT:
            cursorRight();
            break;
        case ESC:
            if(_parent) ((Application*)_parent)->running(false);
            break;
        }
    }
}



//some parenting magic
void 
Canvas::parent(Widget *_parent)
{
    Widget::parent(_parent);

    if(_parent) {
        //copy width and height 
        width(_parent->width());
        height(_parent->height());

        //put cursor in the middle
        cout << cursorPosition(cx, cy) << ' ';
        cx = width()/2+1;
        cy = height()/2+1;
        cout << cursorPosition(cx, cy) << '+';
        cout.flush();
    }
}



//cursor movement commands
void 
Canvas::cursorUp()
{
    //clear the cursor
    cout << cursorPosition(cx, cy) << ' ';

    //move the cursor
    cy--;
    if(cy<1) cy=1;

    //show the cursor
    cout << cursorPosition(cx, cy) << '+';
    cout.flush();
}


void 
Canvas::cursorDown()
{
    //clear the cursor
    cout << cursorPosition(cx, cy) << ' ';

    //move the cursor
    cy++;
    if(cy>height()) cy=height();

    //show the cursor
    cout << cursorPosition(cx, cy) << '+';
    cout.flush();
}


void 
Canvas::cursorLeft()
{
    //clear the cursor
    cout << cursorPosition(cx, cy) << ' ';

    //move the cursor
    cx--;
    if(cx<1) cx=1;

    //show the cursor
    cout << cursorPosition(cx, cy) << '+';
    cout.flush();
}


void 
Canvas::cursorRight()
{

    //clear the cursor
    cout << cursorPosition(cx, cy) << ' ';

    //move the cursor
    cx++;
    if(cx>width()) cx=width();

    //show the cursor
    cout << cursorPosition(cx, cy) << '+';
    cout.flush();
}