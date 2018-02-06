// File: robot.h
// Purpose: This is a class definition for a simulation of a differential drive
//          non-holonomic robot.
#ifndef ROBOT_H
#define ROBOT_H

class Robot
{
public:
  //Consructors
  Robot();
  Robot(const Robot &other);
  Robot(int size, int x, int y, double heading);

  //Destructor
  ~Robot();

  //motion
  void forward(int dist);
  void backward(int dist);
  void turnLeft(double rad);
  void turnRight(double rad);

  //control
  void stop();
  void start();
  void setSpeed(int s);


  //sensor
  //TODO: int distance(direction);
  
private:
  int x;  //location
  int y;  //location
  int speed;
  int size;
  double heading;  //heading in radians

  void move(int d);      //move along our heading
  void turn(double rad); //turn to a new heading
};

#endif
