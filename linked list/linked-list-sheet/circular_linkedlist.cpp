#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
void insertAfter(int val, int pos, node *&head)
{
    node *newnode = new node{val, NULL};
    node *prev = head;

    if (head == NULL)
    {
        head = newnode;
        newnode->next = newnode;
        return;
    }
    else if (pos == 0)
    {

        while (prev->next != head)
        {
            prev = prev->next;
        }
        newnode->next = head;
        head = newnode;

        prev->next = newnode;
        return;
    }
    else
    {
        while (prev->data != pos && prev->next != head)
        {
            prev = prev->next;
        }
        if (prev->data != pos)
        {
            delete newnode;
            return;
        }
        
        newnode->next = prev->next;
        prev->next = newnode;
        return;
    }
}

int main()
{

    node *head = NULL;

    insertAfter(10, 0, head);
    insertAfter(0, 0, head);
    insertAfter(20, 10, head);
    insertAfter(15, 10, head);
    insertAfter(30, 20, head);

    node *i = head;
    do
    {
        cout << i->data << endl;
        i = i->next;
    } while (i != head);
    return 0;
}
