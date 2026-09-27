#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void add(int a)
{
    a = a + 10;
    cout << a << endl;
}

void addptr(int *a)
{
    *a = *a + 10;
    cout << *a << endl;
}

int main()
{

    // getting the address of a variable
    int x = 5;
    cout << x << endl;
    cout << &x << endl;

    // pointer
    int *ptr = &x;
    cout << ptr << endl;
    cout << *ptr << endl;

    // pass by reference
    addptr(&x);
    cout << x;
    return 0;
}
