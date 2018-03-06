#include "paddle.h"
#include "termmanip.h"
#include <iostream>

using namespace std;

void Paddle::display()
{
    //make spaces visible
    cout << reverseVideo;

    //draw the spaces
    for(int i=0; i<height(); i++) {
	cout << cursorPosition(x(), y()+i) << " ";
    }

    //switch back to normal view
    cout << normal;

    //force the display
    cout.flush();
}


void Paddle::paddleDown()
{
    //use the widget api to add 1 to the y axis
    clear();
    y(y() + 1);
    display();
}


void Paddle::paddleUp()
{
    //use the widget api to add 1 to the y axis
    clear();
    y(y() - 1);
    display();
}
