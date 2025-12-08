#include <iostream>
#include <fstream>
using namespace std;

int main()
{ // Write
    ofstream output_file("file.txt");
    if (!output_file.is_open())
    {
        cout << "File not found" << endl;
        return 1;
    }
    output_file << "Hello World" << endl
                << "Goodbye World" << endl;
    output_file.close();
    // Read
    ifstream input_file("file.txt");
    if (input_file.is_open())
    {
        char c;
        input_file.seekg(0, ios::end);
        streampos pos = input_file.tellg();
        while (pos > 0)
        {
            pos -= 1;
            input_file.seekg(pos);
            c = input_file.get();
            cout << input_file.tellg() << " | ";
            cout << c << endl;
        }

        input_file.close();
    }

    else
    {
        cout << "File not found" << endl;
        return 1;
    }
    return 0;
}
