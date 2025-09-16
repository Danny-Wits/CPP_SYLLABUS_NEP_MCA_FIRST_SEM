#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int x;
    cout << "Please enter the no. here : ";
    cin >> x;

    if (x <= 1)
    {
        cout << x << " is not prime";
    }
    else
    {
        int limit = sqrt(x);
        bool isPrime = true;
        for (int i = 2; i <= limit; i++)
        {
            if (x % i == 0)
            {
                cout << x << " is not prime";
                isPrime = false;
                break;
            }
        }
        if (isPrime)
        {
            cout << "The number is prime";
        }
    }

    return 0;
}