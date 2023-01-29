#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }

        cout << "Memory is free for node with value:- " << val << "\n";
    }
};

void printDLL(Node *&head)
{
    Node *temp = head;

    if (temp == NULL)
    {
        cout << "DLL is empty\n";
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
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtBeg(Node *&head, int d)
{
    Node *node = new Node(d);
    Node *temp = head;

    if (head == NULL)
        head = node;
    else
    {
        node->next = head;
        head->prev = node;
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
        node->prev = temp;
    }
}

// Inset a node at position
void insertAtPosition(Node *&head, int position, int d)
{
    Node *node = new Node(d);
    Node *temp = head;

    if (position == 1)
    {
        insertAtBeg(head, d);
        return;
    }

    int cnt = 1;
    while (cnt != position - 1)
    {
        cnt++;
        temp = temp->next;
    }
    node->next = temp->next;
    node->prev = temp;
    temp->next = node;
}

// Delete a node at postion node
void deleteNode(Node *&head, int position)
{
    Node *temp = head;

    // deleting first node
    if (position == 1)
    {
        head = temp->next;
        temp->next = NULL;
        head->prev = NULL;

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

    // deleting last node
    if (nodeToDelete->next == NULL)
    {
        temp->next=NULL;
        nodeToDelete->prev=NULL;
        nodeToDelete->next=NULL;

        delete nodeToDelete;

        return;
    }

    // deleting any node
    temp->next = nodeToDelete->next;
    nodeToDelete->next->prev = temp;

    nodeToDelete->next = NULL;
    nodeToDelete->prev = NULL;

    delete nodeToDelete;
}

int main()
{
    Node *head = NULL;

    insertAtBeg(head, 10);
    insertAtBeg(head, 110);
    insertAtEnd(head, 1650);
    insertAtEnd(head, 16520);
    printDLL(head);
    insertAtPosition(head, 5, 1);
    printDLL(head);
    insertAtPosition(head, 1, 0);
    printDLL(head);
    insertAtPosition(head, 2, 70);
    printDLL(head);

    deleteNode(head, 1);
    printDLL(head);
    deleteNode(head, 6);
    printDLL(head);
    deleteNode(head, 3);
    printDLL(head);

    return 0;
}