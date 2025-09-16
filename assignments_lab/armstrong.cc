#include <iostream>
#include <cmath>
using namespace std;
bool isArmstrong(int);
int digitCount(int);
int main()
{
    for (int i = 0; i < 100000; i++)
    {
        if (isArmstrong(i))
        {
            cout << i << endl;
        }
    }

    return 0;
}
int digitCount(int x)
{
    if (x == 0)
        return 1;
    int dCount = 0;
    while (x > 0)
    {
        x /= 10;
        dCount++;
    }
    return dCount;
}
bool isArmstrong(int x)
{
    int value = x;
    int digits = digitCount(x);

    int sum = 0;

    while (x > 0)
    {
        sum += pow(x % 10, digits);
        x /= 10;
    }
    return value == sum;
}