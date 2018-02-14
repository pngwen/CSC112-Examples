//Point class, the easiest shape!
#ifndef POINT_H
#define POINT_H
#include "shape.h"

class Point : public Shape
{
public:
    Point();  //public constructor
  
    //required widget functions
    virtual void display();
    virtual void handleEvent(Event *e);

    //shape specific functions
    virtual bool isComplete();
    virtual void addPoint(int _x, int _y);
  
private:
    bool _complete;
};

#endif
