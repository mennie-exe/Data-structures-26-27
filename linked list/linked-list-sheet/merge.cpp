#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node *next;
};
node* mergeLists(node* list1, node* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    node* temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = list2;
    return list1;
}

int main() {
    return 0;
}