//! Enumerations

//! Enumerations
//
// Enumerations are user-defined data types that allow
// for a variable to be a set of predefined constants.
//
// Enumerations are used when we know the possible values
// a variable can take. e.g. colors, days of the week, etc.
//
// Enumerations make the code more readable and easier to
// understand and maintain.
#include <iostream>

// enumeration for colors
enum Color
{
    BLACK = 0,   // black color
    GRAY = 128,  // gray color
    WHITE = 255, // white color
};

using namespace std;

int main()
{
    int c;
    // prompt user for the color code
    cout << "Enter the color code: ";
    cin >> c;
    cout << endl;

    // switch statement to check the color code
    switch (c)
    {
    case BLACK:
        // black color
        cout << "The color is BLACK" << endl;
        break;
    case GRAY:
        // gray color
        cout << "The color is GRAY" << endl;
        break;
    case WHITE:
        // white color
        cout << "The color is WHITE" << endl;
        break;
    default:
        // invalid color code
        cout << "Invalid color code" << endl;
        break;
    }

    return 0;
}
