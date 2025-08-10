//! Passing and returning by value and reference
#include <iostream>
using namespace std;

struct Tree
{
    int height;
    string name;

    Tree(int height, string name)
    {
        Tree::height = height;
        Tree::name = name;
    }
    void grow()
    {
        height++;
    }
    void show()
    {
        cout << name << " is " << height << " feet tall" << endl;
    }
};

Tree *grow__by_reference(Tree *t)
{
    // Pass a pointer to a Tree to grow__by_reference
    // This function takes a pointer to a Tree and returns a pointer to the same Tree
    // Because the function takes a pointer to a Tree, it can modify the original Tree
    (*t).grow();
    return t;
}
Tree grow__by_value(Tree t)
{
    // Pass a Tree to grow__by_value
    // This function takes a copy of a Tree and returns a copy of the Tree
    // Because the function takes a copy of the Tree, it does not modify the original Tree
    t.grow();
    return t;
}
int main()
{
    Tree t2(5, "Value Tree");
    cout << "The original tree height is " << t2.height << endl;
    Tree t2_r = grow__by_value(t2);
    cout << "Original :";
    t2.show();
    cout << "Returned :";
    t2_r.show();

    Tree t1(5, "Reference Tree");
    cout << "The original tree height is " << t1.height << endl;
    // Dereference the pointer returned by grow__by_reference() to access the Tree
    Tree t1_r = *grow__by_reference(&t1);

    cout << "Original :";
    t1.show();
    cout << "Returned :";
    t1_r.show();

    return 0;
}
