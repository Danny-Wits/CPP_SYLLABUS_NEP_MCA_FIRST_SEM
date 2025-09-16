#include <iostream>

using namespace std;

int sort(int[], int);

int main()
{
    int arr[5] = {5, 4, 3, 2, 1};
    for (int i : arr)
    {
        cout << i << ",";
    }
    sort(arr, 5);
    cout << endl;
    for (int i : arr)
    {
        cout << i << ",";
    }
    return 0;
}
int sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}