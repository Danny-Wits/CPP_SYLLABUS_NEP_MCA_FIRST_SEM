// Variables and Storage Class
// Variable is a named memory location
// Storage class tells the compiler where to store the variable and for how long
// There are four major storage classes in C++:

// auto
// register
// static
// extern

// auto : The auto is the default storage for CPP.
// it is used to create a variable which is destroyed at the end of the scope.
#include <iostream>
using namespace std;
void auto_test()
{
    {
        int x = 10;
        // auto is implicit
        // the above line equates to
        // auto int x = 10;
        cout << x << endl;
    }
    // can't access x here ... as it it out of the scope
}

// Register: it is used to create a variable which is stored in the register for fast access
void register_test()
{
    register int fast_x = 10;
    cout << fast_x << endl;
    // scope is the same as auto
}
// Static : it is used to create a variable which stays in memory until the program is terminated

void static_test()
{
    static int static_x = 10;
    static_x++;
    cout << static_x << endl;
}
// Extern : it is used to create a variable which is defined in another source file
// we have a variable x in file called global.cpp

#include "global.cpp"
void extern_test()
{
    extern int x;
    cout << x << endl;
}

int main()
{
    auto_test();

    register_test();

    static_test();
    static_test();
    // static variables are initialized only once and stored in the memory for the duration of the program
    // so the second call will print 11

    extern_test();

    return 0;
}