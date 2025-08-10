// Datatypes and IO statements
#include <iostream>

using namespace std;

int main()
{

    // integer types
    int i;
    short s;
    long l;
    long long ll;

    // floating point types
    float f;
    double d;
    long double ld;

    // character type
    char c;

    // boolean type
    bool b;

    //  input
    //  cout : standard output
    //  << : insertion operator
    //  cin: standard input
    //  >>: extraction operator

    cout << "Enter an integer: ";
    cin >> i;
    cout << "Enter a short: ";
    cin >> s;
    cout << "Enter a long: ";
    cin >> l;
    cout << "Enter a long long: ";
    cin >> ll;
    cout << "Enter a float: ";
    cin >> f;
    cout << "Enter a double: ";
    cin >> d;
    cout << "Enter a long double: ";
    cin >> ld;
    cout << "Enter a character: ";
    cin >> c;
    cout << "Enter a boolean: ";
    cin >> b;
    // output
    cout << "i = " << i << " (sizeof(i) = " << sizeof(i) << ")" << endl;
    cout << "s = " << s << " (sizeof(s) = " << sizeof(s) << ")" << endl;
    cout << "l = " << l << " (sizeof(l) = " << sizeof(l) << ")" << endl;
    cout << "ll = " << ll << " (sizeof(ll) = " << sizeof(ll) << ")" << endl;
    cout << "f = " << f << " (sizeof(f) = " << sizeof(f) << ")" << endl;
    cout << "d = " << d << " (sizeof(d) = " << sizeof(d) << ")" << endl;
    cout << "ld = " << ld << " (sizeof(ld) = " << sizeof(ld) << ")" << endl;
    cout << "c = " << c << " (sizeof(c) = " << sizeof(c) << ")" << endl;
    cout << "b = " << b << " (sizeof(b) = " << sizeof(b) << ")" << endl;

    // returning 0 on success
    return 0;
}