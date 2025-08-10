//! Reference Args

#include <iostream>
using namespace std;

// references act the same as pointers,but it is dereferenced
// references are also used to alias(give a nickname to) a variable
void increment(int &x)
{
    // simple access
    x++;
}
// above function acts the same as this :
void increment(int *x)
{
    // extra dereferencing
    (*x)++;
}
int main()
{
    int a = 10;
    cout << "Before the pass :" << a << endl;
    increment(a);
    cout << "After the pass :" << a << endl;
    return 0;
}