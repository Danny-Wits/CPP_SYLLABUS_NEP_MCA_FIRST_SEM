#include <iostream>
using namespace std;

class Demo
{
public:
    int *ptr;

    Demo(int x)
    {
        ptr = new int(x);
        cout << "Normal Constructor" << endl;
    }

    Demo(const Demo &d)
    {
        ptr = new int(*d.ptr);
        cout << "Copy Constructor" << endl;
    }

    Demo(Demo &&d) noexcept
    {
        ptr = d.ptr;
        d.ptr = nullptr;
        cout << "Move Constructor" << endl;
    }

    ~Demo()
    {
        delete ptr;
    }
};

Demo create()
{
    return Demo(100); // temporary object (rvalue)
}

int main()
{
    Demo d(10);
    Demo a(Demo(20));
    cout << *a.ptr << endl;
    int *arr = new int[100];
    delete[] arr;
    return 0;
}
