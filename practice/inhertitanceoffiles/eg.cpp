#include <iostream>
using namespace std;

class Cake
{
public:
    virtual void setcake()
    {
        cout << "Base setcake()" << endl;
    }

};

class DerivedCake : public Cake
{
public:
    void setcake() 
    {
        Cake::setcake(); // Call base class setcake()
        setnapkins();    // Call derived class setnapkins()
        setwrapping();    // Call derived class setwrapping()
        cout << "Derived setcake()" << endl;
    }

    void setnapkins() 
    {
        cout << "Derived setnapkins()" << endl;
    }

    void setwrapping() 
    {
        cout << "Derived setwrapping()" << endl;
    }
};

int main()
{
    Cake *c=new DerivedCake();
    c->setcake();

    return 0;
}
