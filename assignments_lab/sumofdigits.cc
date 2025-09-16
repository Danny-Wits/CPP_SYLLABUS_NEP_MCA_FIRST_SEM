#include <iostream>
using namespace std;

int main()
{

    int x;
    cout << "Enter the number here : ";
    cin >> x;

    int sum = 0;

    while (x > 0)
    {
        sum += (x % 10);
        x /= 10;
    }

    cout << "Sum : " << sum;
    return 0;
}