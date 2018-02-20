#include "matrix.h"
#include <iostream>

using namespace std;


int main()
{
    int m, n;

    // get the dimensions
    cout << "M: ";
    cin >> m;
    cout << "N: ";
    cin >> n;

    //read matrix a
    cout << "A=" << endl;
    Matrix a(m, n);
    cin >> a;

    //read matrix b
    cout << "B=" << endl;
    Matrix b(m,n);
    cin >> b;

    cout << "A" << endl
	 << a << endl << endl;

    cout << "B" << endl
	 << b << endl << endl;

    cout << "A+B=" << endl
	 << a+b << endl;

    cout << "A*2=" << endl
	 << a * 2 << endl;

    cout << "2 * A = " << endl
	 << 2 * a << endl;
}
