#include <iostream>
#include <vector>
#include <string>
#include "bigNumber.h"
#include "term.h"

using namespace std;

static vector<vector<string>> DIGIT = {
    { "#####",
      "#   #",
      "#   #",
      "#   #",
      "#####"},
      
    { "  #  ",
      "  #  ",
      "  #  ",
      "  #  ",
      "  #  "},
      
    { "#####",
      "    #",
      "#####",
      "#    ",
      "#####"},
      
    { "#####",
      "    #",
      "#####",
      "    #",
      "#####"},
      
    { "#   #",
      "#   #",
      "#####",
      "    #",
      "    #"},

    { "#####",
      "#    ",
      "#####",
      "    #",
      "#####"},
      
    { "#####",
      "#    ",
      "#####",
      "#   #",
      "#####"},

    { "#####",
      "    #",
      "    #",
      "    #",
      "    #"},
      
    { "#####",
      "#   #",
      "#####",
      "#   #",
      "#####"},
      
    { "#####",
      "#   #",
      "#####",
      "    #",
      "    #"}
};


//widget display
void BigNumber::display()
{
    //display the rows
    for(int i=0; i<height(); i++) {
	//go to the beginning of the row
	cout << cursorPosition(x(), y() + i);

	
	for(int j=0; j<width(); j++) {
	    if(DIGIT[value()][i][j] == '#') {
		cout << reverseVideo << ' ' << normal;
	    } else {
		cout << ' ';
	    }
	}
    }

    cout.flush();
}



//accessors and mutators
void BigNumber::value(int _value)
{
    //clear, set, and display
    clear();
    this->_value = _value;
    display();
}


int BigNumber::value()
{
    return _value;
}
