#include <iostream>
#include <string>
#include "application.h"
#include "paddle.h"
#include "pong.h"
#include "term.h"

using namespace std;

//constructors
Pong::Pong(int _x, int _y) : Widget(_x, _y, 80, 24), player(1, 11), computer(80, 11), pnum(34, 1), cnum(43, 1)
{
    //set the delay and start the timer
    t.delay(0.033);
    t.receiver(this);
    t.start();

    //start the ball on its way
    ball.vx(15.0);
    ball.vy(15.0);

    playerPoints = 0;
    computerPoints = 0;
}
Pong::Pong() : Pong(1, 1) { /* nothing to see here */ }



void
Pong::handleEvent(Event *e)
{
    //handle tick events
    if(e->type() == "tick") {
	ball.handleEvent(e);
	bounce();
	computerMove();

	if(playerScore() or computerScore()) {
	    if(playerScore()) {
		playerPoints++;
		pnum.value(playerPoints);
	    } else {
		computerPoints++;
		cnum.value(computerPoints);
	    }
	    ball = Ball();
	    ball.vx(15);
	    ball.vy(15);
	}

	display();
    }

    //handle keyboard events
    if(e->type() == "keyboard") {
	//we got a keyboard event!
	KeyboardEvent *kb = (KeyboardEvent *)e;  //cast to a kb event
	if(kb->key() == UP) {
	    if(player.y() > 1){
		player.paddleUp();
	    }
	} else if(kb->key() == DOWN) {
	    if(player.y() < 24 - player.height()) {
		player.paddleDown();
	    }
	}
    }
}



void
Pong::display()
{
    ball.display();
    player.display();
    computer.display();
    pnum.display();
    cnum.display();
}

void
Pong::computerMove()
{
    if(ball.y() > computer.y() + 1 and computer.y() < 21) {
	computer.paddleDown();
    } else if (ball.y() < computer.y() + 1 and computer.y() > 1) {
	computer.paddleUp();
    }
}


void
Pong::bounce()
{
    //paddle bounce
    if(ball.x() <= 1 and ball.y() >= player.y() and ball.y() <= player.y()+2) {
	ball.vx(-ball.vx());  //rebound in the x direction
    }

    if(ball.x() >= 80 and ball.y() >= computer.y() and ball.y() <= computer.y()+2) {
	ball.vx(-ball.vx());  //rebound in the x direction
    }

    //edge bounce
    if(ball.y() <=1 or ball.y() >= 24) {
	ball.vy(-ball.vy());
    }
}


bool
Pong::playerScore()
{
    return ball.x() > 80;
}


bool
Pong::computerScore()
{
    return ball.x() < 1;
}
