// Functions – Passing Arguments
#include <iostream>
using namespace std;
// Prints the string argument to the console
void write(string s)
{
    cout << s << endl;
}

// Returns the sum of two integers
int sum(int i, int j)
{
    return i + j;
}

int main()
{
    write("Hello");
    cout << sum(2, 3) << endl;
    return 0;
}