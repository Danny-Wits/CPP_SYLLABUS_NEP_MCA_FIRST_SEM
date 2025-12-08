// constructor with function argument
#include <iostream>
using namespace std;

class Rectangle
{
    int length;
    int breadth;

public:
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
    int area()
    {
        return length * breadth;
    }
};

int main()
{
    Rectangle r(10, 20);
    cout << r.area() << endl;
    return 0;
}