#include <iostream>

using namespace std;

class Mammal 
{
public:
    Mammal()
    {
        cout << "Mammal Constructed" << endl;
    }
    
    virtual void speak()=0; // pure virtual can't provide implementation in the base class
    
    
    virtual void eat()
    {
        cout << "YUM!" << endl;
        speak();
    }

    virtual ~Mammal()
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

    virtual void speak()
    {
        cout << "Maaaaaaaaah" << endl;
    }

    virtual ~Alpaca()
    {
        speak();
        speak();
        cout << "Alpaca Euthanized" << endl;
    }
};


int main()
{
    Alpaca *al;
	Alpaca b;
    Mammal *m;
    Mammal *m2;
	Mammal *m3;
	m3 = &b;
	m3 -> speak();

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