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
            this->next = NULL;
        }

        cout << "Memory is free for node with value:- " << val << "\n";
    }
};

void printLL(Node *&head)
{
    Node *temp = head;
    if (temp == NULL)
    {
        cout << "LL is empty\n";
        return;
    }
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int getLength(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtBeg(Node *&head, int d)
{
    Node *node = new Node(d);
    if (head == NULL)
        head = node;
    else
    {
        node->next = head;
        head = node;
    }
}

void insertAtEnd(Node *&head, int d)
{
    Node *node = new Node(d);
    Node *temp = head;
    if (temp == NULL)
        head = node;
    else
    {
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = node;
    }
}

// Insert a node at position
void insertAtPosition(Node *&head, int position, int d)
{

    Node *temp = head;
    Node *node = new Node(d);

    if (position == 1)
    {
        insertAtBeg(head, d);
        return;
    }

    int cnt = 1; // As we are already on first node
    while (cnt != position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    node->next = temp->next;
    temp->next = node;
}

// Delete a node at position Node
void deleteNode(Node *&head, int position)
{
    Node *temp = head;

    if (position == 1)
    {
        head = temp->next;
        temp->next = NULL;

        delete temp;

        return;
    }

    int cnt = 1;
    while (cnt != position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    nodeToDelete->next = NULL;

    delete nodeToDelete;
}

int main()
{
    Node *head = NULL;

    // cout << "Length of LL:- " << getLength(head) << "\n";
    // printLL(head);
    insertAtBeg(head, 20);
    insertAtBeg(head, 10);
    insertAtEnd(head, 40);
    insertAtEnd(head, 30);
    printLL(head);
    insertAtPosition(head, 1, 50);
    printLL(head);
    insertAtPosition(head, 4, 60);
    insertAtPosition(head, 7, 70);
    printLL(head);

    deleteNode(head, 7);
    printLL(head);
    deleteNode(head, 3);
    printLL(head);
    deleteNode(head, 5);
    printLL(head);
    deleteNode(head, 1);
    printLL(head);
    // printLL(head);
    // cout << "Length of LL:- " << getLength(head) << "\n";

    return 0;
}