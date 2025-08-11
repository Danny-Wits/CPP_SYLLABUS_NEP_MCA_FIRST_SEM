// Inline functions

#include <iostream>
using namespace std;

// inline functions are used to reduce the execution time of a function
// by replacing the function call with the function body
// !!These don't support recursive functions as there is no call to push it to the stack.
inline int add(int a, int b)
{
    return a + b;
}

int main()
{
    // add(1,2) will be replaced with 1+2
    cout << add(1, 2) << endl;
    return 0;
}
