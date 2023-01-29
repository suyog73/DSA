#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
    }

    ~Node()
    {
        int val = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }

        cout << "Memory is free for node with value:- " << val << "\n";
    }
};

// Insert a node after an element given
void insertNode(Node *&tail, int element, int d)
{
    Node *node = new Node(d);

    if (tail == NULL)
    {
        tail = node;
        return;
    }

    Node *temp = tail;

    do
    {
        if (temp->data == element)
            break;

        temp = temp->next;
    } while (temp != tail);
}

void deleteNode(Node *&tail, int d)
{
}

int main()
{

    return 0;
}