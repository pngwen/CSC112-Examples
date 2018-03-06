//A test driver for the paddle class.
#include <iostream>
#include <unistd.h>
#include "paddle.h"
#include "term.h"

using namespace std;

int main()
{
    Paddle *testPaddle = new Paddle(40, 1);

    //clear the screen and display the paddle
    cout << clearScreen << cursorOff;
    testPaddle->display();
    cout.flush();

    //move it down 24 rows
    for(int i=0; i<24; i++) {
	testPaddle->paddleDown();
	usleep(250000);
    }

    //move it up 24 rows
    for(int i=0; i<24; i++) {
	testPaddle->paddleUp();
	usleep(250000);
    }

    cout << cursorOn;
    cout.flush();

    return 0;
}
