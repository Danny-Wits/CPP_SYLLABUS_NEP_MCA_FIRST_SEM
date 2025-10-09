//! Structs
//
// A struct is a user-defined data type that allows
// storing multiple values of different types in a single unit.
//
// In this example, we define a struct called Student that
// has three member variables: an integer for the roll number,
// a string for the name, and an integer for the marks.
//
// The struct also has a constructor and a method to display
// the member variables.
#include <iostream>
using namespace std;

struct Student
{
private:
    // member variables
    int roll_no;
    string name;
    int marks;

public:
    // constructor
    Student(int roll_no, string name, int marks)
    {
        // using the scope resolution operator to
        // access the member variables of the same name as the parameters
        Student::roll_no = roll_no;
        Student::name = name;
        Student::marks = marks;
    }

    // method to display the member variables
    void display()
    {
        cout << roll_no << " " << name << " " << marks << endl;
    }
};

int main()
{
    // create an instance of the struct using the constructor
    Student s1(1, "Danny", 100);

    // call the display method to print the member variables
    s1.display();

    // create a pointer to an instance of the struct
    Student *s2 = new Student(2, "Raju", 99);

    // call the display method to print the member variables
    (*s2).display();

    // don't forget to delete the dynamically allocated memory
    delete s2;

    return 0;
}
