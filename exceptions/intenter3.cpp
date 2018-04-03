#include <iostream>
#include <exception>
#include <limits>

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
        try {
            x = getInt("Enter a number -1 to exit: ");
        } catch(const invalid_argument &ex) {
            cerr << "Invalid entry.  Please try again." << endl;
            
            //clear out the wayward input and reset flags
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            //try again
            continue;
        }
        if(x != -1) { 
            total+=x;
            count++;
        }
    } while(x != -1);
    
    cout << "Average: " << total/count << endl;
}