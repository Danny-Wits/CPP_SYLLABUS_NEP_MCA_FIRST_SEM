#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;
const double ROOT_FIVE = sqrt(5);
const double ROOT_FIVE_RECIPROCAL = 1 / ROOT_FIVE;
int fibonacci_recursive(int n)
{
    return (n == 0 || n == 1) ? n : (fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2));
}

int fibonacci_binets(int n)
{
    double A = ROOT_FIVE_RECIPROCAL;
    double B = -A;
    double r1 = (1 + ROOT_FIVE) / 2;
    double r2 = (1 - ROOT_FIVE) / 2;
    return (int)round(A * pow(r1, n) + B * pow(r2, n));
}

void time_test(int n)
{
    auto start = chrono::high_resolution_clock::now();
    fibonacci_recursive(n);
    auto end = chrono::high_resolution_clock::now();
    auto duration_recursive = end - start;
    start = chrono::high_resolution_clock::now();
    fibonacci_binets(n);
    end = chrono::high_resolution_clock::now();
    auto duration_binets = end - start;
    cout << "Recursive : " << duration_recursive.count() / 1000000 << "ms | Binets : " << duration_binets.count() / 1000000 << "ms" << endl;
}
int main()
{

    for (int i = 0; i < 30; i++)
    {
        int fb = fibonacci_binets(i);
        int fr = fibonacci_recursive(i);
        cout << "Binets : " << fb << " Recursive : " << fr << " ";
        if (fb == fr)
        {
            cout << " ok" << endl;
        }
        else
        {
            cout << " failed" << endl;
        }
    }
    cout << "-----TIME TEST-----" << endl;
    for (int i = 30; i <= 45; i++)
    {
        time_test(i);
    }
    return 0;
}