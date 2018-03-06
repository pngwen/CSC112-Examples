// Class definition for the big number widget
// Big Numbers are 5 rows tall by 5 columns wide
#ifndef BIGNUMBER_H
#define BIGNUMBER_H
#include "widget.h"

class BigNumber : public Widget
{
public:
    //constructors
    BigNumber() : Widget(1, 1, 5, 5), _value(0) { /* do nothing */ }
    BigNumber(int _x, int _y) : Widget(_x, _y, 5, 5), _value(0) { /* do nothing */ }

    //event handler does nothing
    virtual void handleEvent(Event *e) { /* do nothing */ }

    //widget display
    virtual void display();

    //accessors and mutators
    virtual void value(int _value);
    virtual int value();
private:
    int _value;   //value being displayed
};

#endif
