#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

void randomize(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = rand() % 100;
    }
}
void print(vector<int> arr)
{
    cout << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}
void swap_elements(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
void bubble_sort(vector<int> &arr)
{

    int size = arr.size();

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap_elements(arr[j], arr[j + 1]);
        }
    }
}

void insertion_sort(vector<int> &arr)
{

    int size = arr.size();

    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(vector<int> &arr)
{

    int size = arr.size();

    for (int i = 0; i < size; i++)
    {
        int min = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}
void merge(vector<int> &arr, vector<int> left, vector<int> right)
{
    int l_size = left.size();
    int r_size = right.size();
    int l = 0, r = 0, i = 0;

    while (l < l_size && r < r_size)
    {
        if (left[l] < right[r])
        {
            arr[i] = left[l];
            l++;
            i++;
        }
        else
        {
            arr[i] = right[r];
            r++;
            i++;
        }
    }
    while (l < l_size)
    {
        arr[i] = left[l];
        l++;
        i++;
    }
    while (r < r_size)
    {
        arr[i] = right[r];
        r++;
        i++;
    }
}
void merge_sort(vector<int> &arr)
{
    int len = arr.size();
    if (len <= 1)
        return;

    int middle = len / 2;

    vector<int> left(arr.begin(), arr.begin() + middle);
    vector<int> right(arr.begin() + middle, arr.end());
    merge_sort(left);
    merge_sort(right);
    merge(arr, left, right);
}

int hoare_partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
        {
            return j;
        }
        swap_elements(arr[i], arr[j]);
    }
}

int lomuto_partition(vector<int> &arr, int low, int high)
{
    int i = low - 1, j = low;

    while (j < high)
    {
        if (arr[j] < arr[high])
        {
            i++;
            swap_elements(arr[j], arr[i]);
        }
        j++;
    }
    swap_elements(arr[high], arr[i + 1]);
    return i + 1;
}
void quick_sort_helper(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int p = lomuto_partition(arr, low, high);
        quick_sort_helper(arr, low, p - 1);
        quick_sort_helper(arr, p + 1, high);
    }
}
void quick_sort(vector<int> &arr)
{
    quick_sort_helper(arr, 0, arr.size() - 1);
}

void test_sort()
{
    vector<int> arr(20);
    randomize(arr);

    // cout << "Before: ";
    // print(arr);

    // Make a copy for validation
    vector<int> expected = arr;

    // Sort using your algorithm
    quick_sort(arr);

    // Sort using STL for comparison
    sort(expected.begin(), expected.end());

    // cout << "After:  ";
    // print(arr);

    // Compare results
    if (arr == expected)
        cout << "Sorting correct\n";
    else
        cout << "Sorting failed\n";
}
int main()
{
    for (int i = 0; i < 10; i++)
    {
        srand(time(0));
        test_sort();
    }

    return 0;
}