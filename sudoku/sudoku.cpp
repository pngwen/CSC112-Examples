#include <iostream>
#include <iomanip>
#include <unistd.h>
#include "termmanip.h"
#include "sudoku.h"

using namespace std;

static void printSeparator();
static bool isValid(vector<int> &puzzle);
static bool checkRow(vector<int> &puzzle, int y);
static bool checkCol(vector<int> &puzzle, int x);
static bool checkSquare(vector<int> &puzzle, int grid);


Sudoku::Sudoku(std::vector<int> &puzzle, bool _animate) : puzzle(puzzle), changeable(81)
{
    //mark all the degrees of freedom
    for(int i=0; i<81; i++) {
        changeable[i] = puzzle[i] == 0;
    }
    
    //initialize whether we are animating or not
    this->_animate = _animate;
} 


Sudoku::~Sudoku()
{
    //delete the next step (if there is one)
    if(nextStep() != nullptr) {
        delete (Sudoku*) nextStep();
    }
}


//returns true if this candidate is invalid or otherwise unworkable.
bool 
Sudoku::reject()
{
    return not isValid(puzzle);
}
    

//returns true if this candidate is a solved puzzle
bool 
Sudoku::solved()
{
    //rejects are not solutions
    if(reject()) {
	return false;
    }

    //if there is a changeable square, then the puzzle is not solved
    for(auto itr = changeable.begin(); itr != changeable.end(); itr++) {
	if(*itr) {
	    return false;
	}
    }

    //we have a valid full puzzle
    return true;
}
    

//returns the next extension of this candidate solution 
//(nullptr if there is none)
Candidate *
Sudoku::next() 
{
    //there are no next positions from a rejected puzzle
    if(reject()) {
	return nullptr;
    }

    //find the next changeable position
    int pos;
    for(pos = 0; pos<changeable.size(); pos++) {
	if(changeable[pos]) {
	    //stop once we find a changeable position
	    break;
	}
    }

    //increment that changeable position
    do {
	puzzle[pos]++;
	if(puzzle[pos] > 9) {
	    return nullptr;
	}
    } while(not isValid(puzzle));

    //return the new puzzle
    Sudoku *ncandidate = new Sudoku(puzzle, animate());

    if(animate()) {
	ncandidate->display();
	usleep(10000);
    }

    return ncandidate;
}



void 
Sudoku::display()
{
    cout << cursorPosition(1,1);

    //print the grid
    for(int i=0; i<81; i++) {
        if(i%9==0) {
            if(i!=0) {
                //the first row needs no termination
                cout << " |"  << endl;
            }
        
            if((i/9)%3==0) {
                printSeparator();
            }
        }
        
        //handle the printing of column separators
        if((i%9)%3 == 0) {
            cout << " |";
        }
        
        //print the number or space
        if(puzzle[i] == 0) {
            cout << setw(2) << ' ';
        } else {
            cout << setw(2) << puzzle[i];
        }
    }
    cout << " |" << endl;
    printSeparator();
}



//get/set the animate flag
void 
Sudoku::animate(bool _animate)
{
    this->_animate = _animate;
}


bool 
Sudoku::animate()
{
    return _animate;
}


static void 
printSeparator()
{
    cout << " +" 
         << setfill('-')
         << setw(8) << '+' << setw(8) << '+' << setw(8) << '+'
         << setfill(' ') << endl;
}



static bool 
isValid(vector<int> &puzzle)
{
    //check all the things
    for(int i=0; i<9; i++) {
        if(not checkRow(puzzle, i)) {
            return false;
        }
        
        if(not checkCol(puzzle, i)) {
            return false;
        }
        
        if(not checkSquare(puzzle, i)) {
            return false;
        }
    }
    
    //we passed all the checks!  No rejection for us!
    return true;
}


static bool 
checkRow(vector<int> &puzzle, int y)
{
    vector<bool> present(9, false);  //count each value
    int i;
    
    //compute the first index
    i = y * 9;
    
    for(int col=0; col<9; col++, i++) {
        if(puzzle[i]!=0) {
            if(present[puzzle[i]-1]) {
                //There can be only one!
                return false;
            } else {
                //I am the one!
                present[puzzle[i]-1] = true;
            }
        }
    }
    
    //if we made it this far, all is well
    return true;
}


static bool 
checkCol(vector<int> &puzzle, int x)
{
    vector<bool> present(9, false);  //count each value
    int i;
    
    //compute the first index
    i = x;
    
    for(int row=0; row<9; row++, i+=9) {
        if(puzzle[i]!=0) {
            if(present[puzzle[i]-1]) {
                //There can be only one!
                return false;
            } else {
                //I am the one!
                present[puzzle[i]-1] = true;
            }
        }
    }
    
    //if we made it this far, all is well
    return true;
}


static bool 
checkSquare(vector<int> &puzzle, int grid)
{
    vector<bool> present(9, false);  //count each value
    int i;
    
    //compute the first index
    i = 27*(grid/3) + 3*(grid%3);
    
    for(int row=0; row<3; row++, i+=6) {
        for(int col=0; col<3; col++, i++){
            if(puzzle[i]!=0) {
                if(present[puzzle[i]-1]) {
                    //There can be only one!
                    return false;
                } else {
                    //I am the one!
                    present[puzzle[i]-1] = true;
                }
            }
        }
    }
    
    //if we made it this far, all is well
    return true;
}
