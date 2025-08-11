// This is a simple CLI Based calculator in C++

#include <iostream>
using namespace std;

enum OPERATION
{
    ADD = '+',
    SUB = '-',
    MUL = '*',
    DIV = '/',
};

struct Calculator
{
    float input1;
    float input2;
    OPERATION current_operation;

    void take_input1()
    {
        cout << "Enter the first no.: ";
        cin >> input1;
        cout << endl;
    }

    void take_input2()
    {
        cout << "Enter the second no.: ";
        cin >> input2;
        cout << endl;
    }
    bool want_to_exit()
    {
        cout << "Do you want to exit? (y/n): ";
        char opt;
        cin >> opt;
        return (opt == 'y' || opt == 'Y');
    }
    void get_operation()
    {
        char opt;
        cout << "Enter the operation: ";
        cin >> opt;
        current_operation = (OPERATION)opt;
        cout << endl;
    }
    void calculate()
    {
        switch (current_operation)
        {
        case ADD:
            cout << input1 + input2 << endl;
            break;
        case SUB:
            cout << input1 - input2 << endl;
            break;
        case MUL:
            cout << input1 * input2 << endl;
            break;
        case DIV:
            cout << input1 / input2 << endl;
            break;
        default:
            cout << "Invalid Operation" << endl;
        }
    }
};
//! Declarations
void run(Calculator c);
int main()
{
    Calculator c;
    run(c);
}
//! Definitions

void run(Calculator c)

{
    system("clear");
    cout << "--------Welcome------------"
         << endl
         << "---This is a Calculator---"
         << endl
         << "### PRESS ANY KEY TO ENTER ###"
         << endl;

    scanf("%*c");
    do
    {
        system("clear");
        c.take_input1();
        c.get_operation();
        c.take_input2();
        c.calculate();

    } while (!c.want_to_exit());
}
