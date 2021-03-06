#include <iostream>
#include <exception>

using namespace std;

int getInt(string prompt)
{
    int x;
    
    cout << prompt;
    cin >> x;
    
    if(not cin) {
        throw invalid_argument("User input not valid");
    }
    
    return x;
}


int main()
{
    int x;
    int total=0;
    int count=0;
    
    do {
        x = getInt("Enter a number -1 to exit: ");
        if(x != -1) { 
            total+=x;
            count++;
        }
    } while(x != -1);
    
    cout << "Average: " << total/count << endl;
}