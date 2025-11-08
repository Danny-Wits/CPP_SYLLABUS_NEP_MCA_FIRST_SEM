#include <iostream>
using namespace std;
class ComplexNumber
{
private:
    double i;
    double j;

public:
    ComplexNumber(double i, double j)
    {
        this->i = i;
        this->j = j;
    };

    ComplexNumber operator+(ComplexNumber other)
    {
        ComplexNumber result(this->i + other.get_i(), this->j + other.get_j());
        return result;
    }
    double operator[](int index)
    {
        return index == 0 ? i : j;
    }
    double get_i()
    {
        return i;
    }
    double get_j()
    {
        return j;
    }
    double get_mag()
    {
        return i * i + j * j;
    }

    friend ostream &operator<<(ostream &os, ComplexNumber &obj);
};
ostream &operator<<(ostream &out, ComplexNumber &obj)
{
    out << obj.get_i() << " + " << obj.get_j() << "i";
    return out;
}
int main()
{
    ComplexNumber c1(1, 2);
    ComplexNumber c2(2, 2);
    ComplexNumber c3 = c1 + c2;
    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3[0] << endl;

    return 0;
}