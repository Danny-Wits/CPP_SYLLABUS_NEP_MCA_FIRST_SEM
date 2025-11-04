#include <iostream>
using namespace std;
template <typename N>
class ComplexNumber
{
private:
    N i;
    N j;

public:
    ComplexNumber(N i, N j)
    {
        this->i = i;
        this->j = j;
    };

    ComplexNumber<N> operator+(const ComplexNumber<N> other) const
    {
        ComplexNumber<N> result(this->i + other.get_i(), this->j + other.get_j());
        return result;
    }
    N get_i() const
    {
        return i;
    }
    N get_j() const
    {
        return j;
    }
    template <typename T>
    friend ostream &operator<<(ostream &os, const ComplexNumber<T> &p);
};
template <typename T>
ostream &operator<<(ostream &out, const ComplexNumber<T> &obj)
{
    out << obj.get_i() << " + " << obj.get_j() << "i";
    return out;
}
int main()
{
    ComplexNumber<int> c1(1, 2);
    ComplexNumber<int> c2(2, 2);
    ComplexNumber<int> c3 = c1 + c2;
    cout << c1 << endl;
    cout << c2 << endl;
    cout << c3 << endl;

    return 0;
}