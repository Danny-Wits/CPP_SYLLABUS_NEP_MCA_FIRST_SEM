#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>
using namespace std;
const int LIMIT = 15;
const int ANIMATION_DELAY = 0;
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
    int limit;
    vector<Disk> pole;
    int index;

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
        {
            throw runtime_error("Invalid disk");
        }
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
    friend void draw_all(Tower t1, Tower t2, Tower t3);
};
void move_disk_from_to(Tower &t1, Tower &t2)
{
    system("clear");
    cout << "Move : D" << t1.peek_disk() << " from T" << t1.index << " to T" << t2.index << endl;
    t2.add_disk(t1.remove_disk());
}

void draw_all(Tower t1, Tower t2, Tower t3)
{
    vector<Tower *> towers = {&t1, &t2, &t3};
    sort(towers.begin(), towers.end(), [](Tower *a, Tower *b)
         { return a->index < b->index; });
    for (Tower *t : towers)
    {
        t->draw();
    }
    Sleep(ANIMATION_DELAY);
}
void hanoi(int limit, Tower &start, Tower &end, Tower &other)
{
    if (limit > 0)
    {
        hanoi(limit - 1, start, other, end);
        move_disk_from_to(start, end);
        draw_all(start, end, other);
        hanoi(limit - 1, other, end, start);
    }
}

int main()
{
    int limit = LIMIT;
    Tower t0(1, limit);
    Tower t1(2, limit);
    Tower t2(3, limit);

    t0.fill(limit);
    hanoi(limit, t0, t2, t1);

    return 0;
}