#include <iostream>
#include <vector>
#include <windows.h>
#include <thread>
using namespace std;
class Disk
{

public:
    string name;
    int value;
    Disk(string name)
    {
        Disk::name = name;
        Disk::value = stoi(name);
    }
};
class Tower
{
    int index;
    int limit;
    vector<Disk> pole;

public:
    Tower(int index, int limit = 10)
    {
        Tower::index = index;
        Tower::limit = limit;
    }
    void add_disk(Disk d)
    {
        if (d.value <= peek_disk())
            pole.push_back(d);
        else
            pole.push_back(d);
    }
    int peek_disk()
    {
        if (is_empty())
        {
            return INT32_MAX;
        }
        return pole[pole.size() - 1].value;
    }
    Disk remove_disk()
    {
        Disk d = pole[pole.size() - 1];
        pole.pop_back();
        return d;
    }
    bool is_empty()
    {
        return pole.empty();
    }
    void draw()
    {
        cout << "|\n|-";
        for (int i = 0; i < limit; i++)
        {
            if (i < pole.size())
            {
                cout << pole[i].name << "-";
            }
            else
            {
                cout << " -";
            }
        }
        cout << "\t\t" << index << "\n|\n";
    }
    void fill(int limit = -1)
    {
        limit = limit == -1 ? Tower::limit : limit;
        for (int i = 0; i < limit; i++)
        {
            Disk d(to_string(limit - i));
            add_disk(d);
        }
    }
    friend void move_disk_from_to(Tower &t1, Tower &t2);
};
void move_disk_from_to(Tower &t1, Tower &t2)
{
    t2.add_disk(t1.remove_disk());
}
void draw_all(Tower t0, Tower t1, Tower t2)
{
    system("clear");
    t0.draw();
    t1.draw();
    t2.draw();
    Sleep(1000);
}

int main()
{
    int limit = 10;
    Tower t0(0, limit);
    Tower t1(1, limit);
    Tower t2(2, limit);
    t0.fill(limit);
    for (int i = 0; i < limit; i++)
    {
        move_disk_from_to(t0, t1);
        draw_all(t0, t1, t2);
    }

    return 0;
}