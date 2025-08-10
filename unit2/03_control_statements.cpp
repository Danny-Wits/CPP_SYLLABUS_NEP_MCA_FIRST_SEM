//! Control Statements

#include <iostream>

using namespace std;

int main()
{

    // if , else , and ladder
    int age;
    cout << "Enter your age here :";
    cin >> age;

    // if condition for invalid age
    if (age > 200 || age < 0)
    {
        cout << "Invalid age, Dude!";
    }
    // if condition for minor
    else if (age < 18)
    {
        cout << "You are a minor";
    }
    // else condition for adult
    else
    {
        cout << "You are an adult";
    }

    // switch case for getting day name

    int day;
    cout << endl
         << "Enter your no. of days of the week here : ";
    cin >> day;
    string day_name;
    switch (day)
    {
    case 1:
        day_name = "Monday";
        break;
    case 2:
        day_name = "Tuesday";
        break;
    case 3:
        day_name = "Wednesday";
        break;
    case 4:
        day_name = "Thursday";
        break;
    case 5:
        day_name = "Friday";
        break;
    case 6:
        day_name = "Saturday";
        break;
    case 7:
        day_name = "Sunday";
        break;
    default:
        day_name = "Invalid Day";
    }

    cout << day_name << endl;

    // loops

    // 1. while loop

    int i = 1;
    cout << "While loop" << endl;
    while (i <= 10)
    {
        cout << i << "-";
        i++;
    }
    cout << ">" << endl;

    // 2. for loop

    cout << "For loop" << endl;
    for (int i = 1; i <= 10; i++)
    {
        cout << i << "-";
    }
    cout << ">" << endl;

    // 3. do while loop

    int j = 1;
    cout << "Do while loop" << endl;
    do
    {
        cout << j << "-";
        j++;
    } while (j <= 10);
    cout << ">" << endl;

    // 4. for each loop

    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "For each loop" << endl;
    for (int x : a)
    {
        cout << x << "-";
    }
    cout << ">" << endl;
    return 0;
}