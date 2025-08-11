// Default Arguments
#include <iostream>
using namespace std;
// Function adds two numbers ...
// but if no arguments are passed, both will be set to 0
// So the default parameters are 0
//@param a  first number
//@param b  second number
//@returns  the sum of a and b
int add(int a = 0, int b = 0)
{
    return a + b;
}
int main()
{ // a was passed to be 0
    // b was not passed
    //  so it will default to zero
    cout << add(1) << endl;
    return 0;
}