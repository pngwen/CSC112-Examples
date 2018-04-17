// This is a class which generates timer events and sends them 
// to a given widget.  The timer event is set as fractions of a
// second via a double.  This uses C++11's thread library to 
// work its magic.
// $Revision: 1.1 $
//   $Log: timer.h,v $
//   Revision 1.1  2017/04/19 01:58:02  1ea49c2b19284e86b645075d033e28d0
//   *** empty log message ***
//
#ifndef TIMER_H
#define TIMER_H
#include <thread>
#include "widget.h"

class Timer
{
public:
    //constructors
    Timer();
    Timer(double _delay);
    
    //destructor
    ~Timer();
    
    //delay control
    virtual void delay(double _delay);
    virtual double delay();
    
    //running control
    virtual bool running();
    virtual void start();
    virtual void stop();
    
    
    //receiver control
    virtual void receiver(Widget *_receiver);
    virtual Widget *receiver();
private:
    void timerLoop();       //the actual loop of the timer
    std::thread *_thread;   //the timer thread
    Widget *_receiver;      //the receiving widget
    double _delay;          //the timer delay
    int    _s;              //whole seconds delay
    int    _us;             //microseconds delay
    bool   _running;        //whether the timer is running
};


class Tick : public Event
{

    virtual std::string type() { return "tick"; }
};
#endif