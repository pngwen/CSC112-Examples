#include <cmath>
#include "robot.h"

//Consructors
Robot::Robot() : speed(0)
{
  //This space left intentionally blank
}


Robot::Robot(const Robot &other)
{
  x = other.x;
  y = other.y;
  speed = other.speed;
  size = other.size;
  heading = other.heading;
}

Robot::Robot(int size, int x, int y, double heading) : size(size), x(x), y(y), heading(heading), speed(0)
{
  //left intentionally blank
}

//Destructor
Robot::~Robot()
{
  //nothing to do (for now)
}

//motion
void Robot::forward(int dist)
{
  move(dist);
}

void Robot::backward(int dist)
{
  move(-dist);
}


void Robot::turnLeft(double rad)
{
  turn(-rad);
}
  
void Robot::turnRight(double rad)
{
  turn(rad);
}

//control
void Robot::stop()
{
  setSpeed(0);
}
  
void Robot::start()
{
  setSpeed(1);
}

void Robot::setSpeed(int s)
{
  speed = s;
}


//real movement
void Robot::move(int d)
{
  int dx, dy;
  double interior_angle;

  //compute the displacement
  interior_angle = M_PI/2.0 - heading;
  dx = cos(interior_angle) * d;
  dy = sin(interior_angle) * d;

  //add the displacement
  x += dx;
  y += dy;
}

void Robot::turn(double rad)
{
  //add to the heading
  heading += rad;

  //correct for going around more than once
  if(heading >= 2*M_PI) {
    int tripsAround = (int)(heading / (2.0*M_PI));
    heading -= tripsAround * 2.0 *M_PI;
  }
}


//sensor
//TODO: int distance(direction);

