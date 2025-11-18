#include <iostream>
#include <stdexcept>
using namespace std;

class DivisionException : public runtime_error
{
public:
    DivisionException() : runtime_error("can't divide by zero") {}
};

template <class T>
auto divide(T x, T y)
{
    if (y == 0)
    {
        throw DivisionException();
    }
    return x / y;
}

int main()
{
    try
    {
        cout << divide(10, 0);
    }
    catch (exception &e)
    {
        cout << e.what();
    }
    cout << endl
         << "DONE!";
    return 0;
}