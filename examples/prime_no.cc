#include <iostream>
#include <math.h>
#include <map>
using namespace std;

bool isPrime(int number)
{
    if (number <= 1)
        return false;
    else if (number == 2)
        return true;
    else if (number % 2 == 0)
        return false;
    int limit = (int)sqrt(number);
    for (int i = 3; i <= limit; i += 2)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

int main()
{
    cout << "Test Start : ------------------------" << endl;
    for (int i = 0; i < 100; i++)
    {
        cout << i << ":";
        cout << (isPrime(i) ? "The number is Prime " : "The number not Prime") << endl;
    }
    cout << "Test End : ------------------------\n\n\n";

    cout << "Enter you number here : ";
    int number;
    cin >> number;
    cout << number << (isPrime(number) ? " is prime " : " is not prime");
    return 0;
}