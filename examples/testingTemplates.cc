#include <iostream>
#include <typeinfo>
using namespace std;

// template function

template <class T1, class T2>
double sum(T1 n1, T2 n2)
{
    return n1 + n2;
}

int main()
{
    cout << typeid(sum(1, 1)).name();
    return 0;
}