#include <iostream>
#include <fstream>
using namespace std;

long file_size(string file_path)
{
    ifstream infile(file_path);
    if (infile.is_open())
    {
        infile.seekg(0, ios::end);
        long size = (long)infile.tellg();
        infile.close();
        return size;
    }
    else
    {
        return -1;
    }
}

class FileStreamManager
{
    fstream file_stream;

public:
    FileStreamManager(string path)
    {
        file_stream.open(path, ios::in);
        cout << "file size : " << file_size(path) << endl;
    }
    ~FileStreamManager()
    {
        file_stream.close();
    }
    void move_forward()
    {
        if (file_stream.eof() || file_stream.fail())
        {
            cout << "Already at the end of the file!" << endl;
            return;
        }
        file_stream.seekg(1, ios::cur);
    }
    void move_backward()
    {
        streampos current_pos = file_stream.tellg();
        if (current_pos <= 0)
        {
            cout << "Already at the start of the file!" << endl;
            return;
        }
        file_stream.seekg(-1, ios::cur);
    }
    char current_char()
    {
        char c = file_stream.get();
        file_stream.seekg(-1, ios::cur);
        return c;
    }
    int current_index()
    {
        return file_stream.tellg();
    }

    void show_message()
    {
        char ch = current_char();
        int index = current_index();
        cout << "\n-------------------------------------------------" << endl;
        cout << "STATUS: READY" << endl;
        cout << "Current Index: " << index << endl;
        cout << "Character: '" << ch << "'" << endl;
        cout << "-------------------------------------------------" << endl;
    }
};

class Game
{
    FileStreamManager &file_manager;

public:
    Game(FileStreamManager &file_manager) : file_manager(file_manager)
    {
        cout << "game created" << endl;
    }

    void play()
    {
        bool endgame = true;
        cout << "Welcome to the game" << endl;
        do
        {
            cout << "Enter 1 to move forward in the file" << endl;
            cout << "Enter 2 to move backward in the file" << endl;
            cout << "Enter 3 to exit the game" << endl;
            int choice;
            cin >> choice;
            system("cls");
            switch (choice)
            {
            case 1:
                file_manager.move_forward();
                file_manager.show_message();
                break;
            case 2:
                file_manager.move_backward();
                file_manager.show_message();
                break;
            case 3:
                endgame = false;
                break;
            }

        } while (endgame);
    }
    ~Game()
    {
        cout << "game destroyed" << endl;
    }
};

int main()
{
    system("cls");
    FileStreamManager file_manager("test.txt");
    Game g(file_manager);
    g.play();
    return 0;
}