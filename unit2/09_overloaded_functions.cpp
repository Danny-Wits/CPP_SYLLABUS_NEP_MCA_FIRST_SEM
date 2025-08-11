// Overloading Function
#include <iostream>
using namespace std;
struct Rectangle
{
    int width;
    int height;
    Rectangle(int width, int height) : width(width), height(height) {}
};

struct Circle
{
    int radius;
    Circle(int radius) : radius(radius) {}
};

// Two functions with the same name 'area' but with different parameters

// Overload area() to compute the area of a Rectangle
// @param r : a Rectangle object
// @return the area of the Rectangle
int area(Rectangle r) { return r.width * r.height; }

// Overload area() to compute the area of a Circle
// @param c : a Circle object
// @return the area of the Circle
int area(Circle c) { return 3.14 * c.radius * c.radius; }

int main()
{
    Rectangle r(10, 20);
    Circle c(5);
    cout << area(r) << endl;
    cout << area(c) << endl;
    return 0;
}