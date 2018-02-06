#include <iostream>

using namespace std;

int main()
{
  int x;  //integer
  int *ptr; //pointer to an int

  ptr = &x;  //we "point at" x
  *ptr = 5;  //assign 5

  cout << "The pointer: " << ptr << endl;
  cout << "*ptr: " << *ptr << endl;
  cout << "x: " << x << endl;
}
