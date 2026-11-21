#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *reverseIterative(node *head)
{
    node *prev = NULL;
    node *curr = head;
    node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// base case in recursion is the simplest form of input that we can actually return an answer for
// بمعنى ان(الbase case) بوصلها لما المشكلة خلاص تكون صغرت جدا لدرجة ان حلها بقا واضح قدامي و مش محتاج recursion تاني
// the rest of the solution is built on that answer

node *reverseRecursive(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{
    return 0;
}