// This is a class which generates timer events and sends them 
// to a given widget.  The timer event is set as fractions of a
// second via a double.  This uses C++11's thread library to 
// work its magic.
// $Revision: 1.1 $
//   $Log: timer.cpp,v $
//   Revision 1.1  2017/04/19 01:58:02  1ea49c2b19284e86b645075d033e28d0
//   *** empty log message ***
//
#include <unistd.h>
#include "timer.h"

using namespace std;


//constructors
Timer::Timer() : Timer(1.0)
{
    //nothing to see here
}


Timer::Timer(double _delay)
{
    delay(_delay);
    this->_thread = nullptr;
    this->_running = false;
    this->_receiver = nullptr;
}
    

//destructor
Timer::~Timer()
{
    if(_thread != nullptr) {
        delete _thread;
    }
}


    
//delay control
void 
Timer::delay(double _delay)
{
    //get the raw delay and then work out seconds and microsecond components
    this->_delay = _delay;
    this->_s = int(_delay * 1000000.0) / 1000000;
    this->_us = int(_delay * 1000000.0) % 1000000;
}


double 
Timer::delay()
{
    return _delay;
}
    

//running control
bool 
Timer::running()
{
    return _running;
}


void 
Timer::start()
{
    //if it is already running, there is nothing to do
    if(running()) {
        return;
    }
    
    //set ourselves to run
    _running = true;
    
    //create the thread
    _thread = new thread(&Timer::timerLoop, this);
}


void 
Timer::stop()
{
    //if we aren't running, no stopping needs to occur
    if(not running()) {
        return;
    }
    
    //set running to false and let the timer tick its last tock
    _running = false;
    _thread->join();
    
    //destroy the thread!
    delete _thread;
}
 

void 
Timer::receiver(Widget *_receiver)
{
    this->_receiver = _receiver;
}


Widget *
Timer::receiver()
{
    return _receiver;
}


void
Timer::timerLoop()
{
    Tick t;
    
    while(running()) {
        //sleep our whole number sleep
        if(_s != 0) {
            sleep(_s);
        }
        
        //sleep for the fractions
        if(_us != 0) {
            usleep(_us);
        }
        
        //pass on the tick event if we have a receiver
        if(running() and _receiver != nullptr) {
            _receiver->handleEvent(&t);
        }
    }
}