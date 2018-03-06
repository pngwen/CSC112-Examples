#include <iostream>
#include "bigNumber.h"
#include "term.h"
#include <unistd.h>

using namespace std;

int main()
{
    BigNumber *num = new BigNumber(40, 10);

    cout << clearScreen << cursorOff;
    for(int i=0; i<=9; i++) {
	num->value(i);
	usleep(500000);
    }
    cout << cursorOn;
}
