#include <iostream>
using namespace std;

class base
{
public:
    virtual void print()
    {
        cout << "Base class call" << endl;
    }
};
class derived : public base
{
public:
    // override keyword is not necessary
    // but it is a good practice
    void print() override
    {
        cout << "Derived class call" << endl;
    }
};
int main()
{
    derived d;
    // storing derived class object in base class pointer
    base *b = &d; // also called upcasting
    b->print();   // output: Derived class call
    base b1;
    b1.print(); // output: Base class call
    return 0;
}