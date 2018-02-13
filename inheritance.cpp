#include <iostream>

using namespace std;

class Mammal
{
public:
    Mammal()
    {
        cout << "Mammal Constructed" << endl;
    }
    
    void speak()
    {
        cout << "There is no distinct mammal sound." << endl;
    }
    
    
    void eat()
    {
        cout << "YUM!" << endl;
        speak();
    }

    ~Mammal()
    {
        cout << "Mammal Destroyed" << endl;
    }
};


class Alpaca : public Mammal
{
public:
    Alpaca()
    {
        cout << "Alpaca Constructed" << endl;
    }
    
    void speak()
    {
        cout << "Maaaaaaaaah" << endl;
    }
    
    ~Alpaca()
    {
        speak();
        speak();
        cout << "Alpaca Euthanized Again" << endl;
    }
};


int main()
{
    Alpaca *al;
    Mammal *m;
    Mammal *m2;
    
    //create an alpaca
    al = new Alpaca;
    
    m = al;
    m2 = new Alpaca;
    
    //make the animal speak
    al->speak();
    al->eat();
    m->speak();
    
    //destroy the alpaca
    delete al;
    delete m2;
    
    return 0;
}