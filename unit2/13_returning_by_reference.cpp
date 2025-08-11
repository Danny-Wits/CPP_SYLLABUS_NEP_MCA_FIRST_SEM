// returning a reference by a function
#include <iostream>
using namespace std;

struct Person
{
    string name;
    int age;

    Person(string name, int age) : name(name), age(age) {}
};

Person &createPerson(string name, int age)
{
    // Remember to always return a reference to a static variable not a local variable
    // otherwise you may access a location that is out of scope
    // Create a static variable

    static Person person(name, age);
    // Returning a Reference (Similar to Pointer but Automatically dereferenced)
    return person;
}

int main()
{
    Person &person = createPerson("John", 20);
    cout << person.name << " is " << person.age << " years old" << endl;
    return 0;
}