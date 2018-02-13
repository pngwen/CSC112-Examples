// A shape for drawing on the canvas
#ifndef SHAPE_H
#define SHAPE_H
#include "widget.h"

class Shape : public Widget
{
public:
  //required widget functions
  virtual void display()=0;
  virtual void handleEvent(Event *e)=0;

  //shape specific stuff
  virtual bool isComplete()=0;
  virtual void addPoint(int _x, int _y)=0;
  
};

#endif
