#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

void insertionSort(node *&head)
{
    node *sorted = NULL;
    node *current = head;

    while (current != NULL)
    {
        node *nextNode = current->next;

        if (sorted == NULL || current->data < sorted->data)
        {
            current->next = sorted;
            sorted = current;
        }
        else
        {
            node *temp = sorted;
            while (temp->next != NULL && temp->next->data <= current->data)
            {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = nextNode;
    }
    head = sorted;
}

int main()
{
    node *head = new node{5, NULL};
    head->next = new node{2, NULL};
    head->next->next = new node{4, NULL};
    head->next->next->next = new node{1, NULL};
    head->next->next->next->next = new node{3, NULL};

    insertionSort(head);

    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
    return 0;
}
