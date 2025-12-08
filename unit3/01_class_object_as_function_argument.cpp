#include <iostream>
using namespace std;
class Object
{
    int x, y;

public:
    Object(int a, int b)
    {
        x = a;
        y = b;
    }
    friend void print(Object obj);
};
void print(Object obj)
{
    cout << obj.x << " " << obj.y << endl;
}

int main()
{
    Object obj(10, 20);
    print(obj);
}