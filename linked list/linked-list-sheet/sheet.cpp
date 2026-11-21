#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};

int main()
{
    // converting existing array into linkedlist
    struct node
    {
        int data;
        node *next;
    };
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    node *head = new node{arr[0], NULL};
    node *prev = head;

    for (int i = 1; i < 7; i++)
    {
        node *temp = new node{arr[i], NULL};
        prev->next = temp;
        prev = temp;
    }

    node *i = head;
    while (i != NULL)
    {
        cout << i->data << endl;
        i = i->next;
    }

    // how to traverse it if it was circular linkedlist ?
    // how to traverse if it was doubly linkedlist ?

    return 0;
}

/*
//static definition of linkedlist
struct student
    {
      int id;
      string name;
      student* next;
    };

    student* s1 = new student{  10 , "menna" , NULL };
    student* s2 = new student{ 20 , "ali" , NULL};
    student* s3 = new student{ 20 , "ali" , NULL};
    s1->next = s2;
    s2->next = s3;

    student* i = s1;

    while (i != NULL)
    {
        cout<< i->name<<endl;
        i = i->next;
    }

*/
