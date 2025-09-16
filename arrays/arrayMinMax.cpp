#include <iostream>
using namespace std;

int min(int[], int);
int max(int[], int);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 12, 23, 21, 321, 123, -10};
    cout << "Min : " << min(arr, 11) << endl;
    cout << "Max : " << max(arr, 11) << endl;
    return 0;
}
int min(int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
    {
        min = (min > arr[i]) ? arr[i] : min;
    }
    return min;
}

int max(int arr[], int size)
{
    int mx = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (mx < arr[i])
        {
            mx = arr[i];
        }
    }
    return mx;
}