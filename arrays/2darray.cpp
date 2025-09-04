#include <iostream>

using namespace std;

void fill2D(int arr2d[3][3])
{
    for (int i = 0; i < 9; i++)
    {
        cout << "Enter the element on " << i / 3 << " , " << i % 3 << " :";
        cin >> arr2d[i / 3][i % 3];
    }
}

void print2D(int arr2d[3][3])
{
    cout << "------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr2d[i][j] << " | ";
        }
        cout << endl;
    }
    cout << "------------" << endl;
}

int **add2d(int arr1[3][3], int arr2[3][3], int sum[3][3])
{
    for (int i = 0; i < 9; i++)
    {
        sum[i / 3][i % 3] = arr1[i / 3][i % 3] + arr2[i / 3][i % 3];
    }
}

int main()
{
    int arr1[3][3];
    int arr2[3][3];
    int sum[3][3];
    fill2D(arr1);
    fill2D(arr2);
    print2D(arr1);
    print2D(arr2);
    add2d(arr1, arr2, sum);
    print2D(sum);
    return 0;
}
