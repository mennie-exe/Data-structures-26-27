#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    // add to front -> O(1)
    void prepend(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // add to end -> O(n)
    void append(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }

    // insert a value -> O(n)
    void insert_after(int target_value, int new_value)
    {
        Node *current = head;

        while (current != nullptr)
        {
            if (current->data == target_value)
            {
                Node *newNode = new Node();
                newNode->data = new_value;
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }

        cout << "Target value not found in the list!" << endl;
    }
    // delete a value -> O(n)
    void remove(int value)
    {
        if (head == nullptr)
            return;

        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *current = head;
        while (current->next != nullptr)
        {
            if (current->next->data == value)
            {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    void print()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            if (current->next == current)
            {
                cout << "[Self-Loop] -> ";
                break;
            }
            current = current->next;
        }
        cout << "null" << endl;
    }

    // reverse the list -> O(n)
    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;

        while (current != nullptr)
        {
            Node *nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
    }

    void copy(Node *p, Node *q, Node *r)
    {
        Node *x = new Node{p->data, nullptr};
        Node *current = x;
        Node *original = p;

        Node *y = nullptr;
        Node *z = nullptr;

        for (int i = 2; i <= 15; i++)
        {
            original = original->next;

            current->next = new Node{original->data, nullptr};
            current = current->next;

            if (original == q)
                y = current;

            if (original == r)
                z = current;
        }
    }

    int sum()
    {
        int total_sum = 0;
        const Node *cursor = head;
        while (cursor != NULL)
        {
            total_sum += cursor->data;
            cursor = cursor->next;
        }
        return total_sum;
    }

    int product()
    {
        int total_product = 1;
        const Node *cursor = head;
        while (cursor != NULL)
        {
            total_product *= cursor->data;
            cursor = cursor->next;
        }
        return total_product;
    }

    int is_sloop()
    {
        Node *current = head;

        while (current != nullptr)
        {
            if (current->next == current)
            {
                return 1; // TRUE
            }
            current = current->next;
        }

        return 0; // FALSE
    }
};

int main()
{
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.prepend(5);

    list.print();

    cout << "Is Sloop? " << list.is_sloop() << endl;

    return 0;
}
