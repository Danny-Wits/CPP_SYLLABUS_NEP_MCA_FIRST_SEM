#include <iostream>
using namespace std;

template <class type>
class dArray
{
    type *container;
    int size;
    int capacity;
    bool isStatic = false;
    const static int DEFAULT_CAPACITY = 5;
    const string delimiter = " ,";

public:
    dArray() : size(0), capacity(DEFAULT_CAPACITY), isStatic(false)
    {
        container = new type[capacity];
    };
    dArray(int size) : size(size), capacity(size), isStatic(true)
    {
        container = new type[capacity];
    }
    dArray(const dArray<type> &other)
    {
        size = other.size;
        capacity = other.capacity;
        isStatic = other.isStatic;
        container = new type[capacity];
        copy(container, other.container, size);
    }
    dArray(initializer_list<type> list) : size(list.size()), capacity(list.size()), isStatic(false)
    {
        container = new type[capacity];
        int i = 0;
        for (type t : list)
        {
            container[i++] = t;
        }
    }
    int get_size()
    {
        return size;
    }
    void copy(type *container, type *other, int to, int from = 0)
    {
        for (int i = from; i < to; i++)
        {
            container[i] = other[i];
        }
    }
    type *get_container()
    {
        return container;
    }
    void grow()
    {
        capacity += 2;
        type *temp = container;
        container = new type[capacity];
        copy(container, temp, size);
        cout << "Resizing to cap :" << capacity << endl;
    }
    // functional methods
    type get_at(int index)
    {
        if (index < 0 || size - 1 < index)
        {
            throw runtime_error("Index out of bounds :" + to_string(index));
        }
        return container[index];
    }
    void add(type element)
    {
        cout << "Size:" << size << endl;
        if (isStatic)
        {
            throw runtime_error("Cannot add to a static array");
        }
        if (!isStatic && size >= capacity)
        {
            grow();
        }
        cout << "adding element at index " << size << endl;
        container[size] = element;
        size++;
    }
    void extend(initializer_list<type> list)
    {
        for (type t : list)
        {
            add(t);
        }
    }
    void slice(int start, int end)
    {
        int i = 0;
        for (int j = start; j < end; j++)
        {
            container[i++] = get_at(j);
        }
        size = i;
    }

    string toString()
    {
        string s = "[ ";
        for (int i = 0; i < size; i++)
        {
            s += to_string(container[i]) + delimiter;
        }
        s += "\b ]";
        return s;
    }
    // overloaded operators

    type operator[](int index)
    {
        return get_at(index);
    }
    dArray<type> operator|(int index)
    {
        dArray<type> d(*this);
        if (index >= 0)
        {
            d.slice(index, size);
        }
        else
        {
            d.slice(0, size + index);
        }
        return d;
    }

    template <class T>
    friend ostream &operator<<(ostream &, dArray<T>);

    ~dArray()
    {
        delete[] container;
    }
};

template <class T>
ostream &operator<<(ostream &out, dArray<T> obj)
{
    return out << obj.toString();
}

int main()
{

    dArray<int> d = {1, 2, 3};

    d.add(4);
    d.extend({5, 6, 7, 8});

    dArray<int> x = (d | 2 | -2);

    cout << d << endl        //[ 1 ,2 ,3 ,4 ,5 ,6 ,7 ,8  ]
         << x << endl        //[ 3 ,4 ,5 ,6 ]
         << (d | 7) << endl; //[ 8  ]

    cout << d[10]; // throws exception
    return 0;
}