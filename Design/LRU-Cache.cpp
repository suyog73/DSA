// Suyog Patil

#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
}

class LRUCache
{
    class Node
    {
    public:
        int key;
        int value;
        Node *prev;
        Node *next;

        Node(int key, int value)
        {
            this->key = key;
            this->value = value;
            prev = next = NULL;
        };
    };

public:
    Node *head, *tail;
    unordered_map<int, Node *> mp;

    int cap = 0;

    void insertAtHead(Node *nodeToInsert, Node *head)
    {
        head->next->prev = nodeToInsert;
        nodeToInsert->next = head->next;
        head->next = nodeToInsert;
        nodeToInsert->prev = head;
    }

    void deleteNode(Node *nodeToDelete)
    {
        nodeToDelete->prev->next = nodeToDelete->next;
        nodeToDelete->next->prev = nodeToDelete->prev;

        nodeToDelete->next = NULL;
        nodeToDelete->prev = NULL;
    }

    LRUCache(int capacity)
    {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (!mp.count(key))
            return -1;

        Node *address = mp[key];
        deleteNode(address);

        insertAtHead(address, head);

        mp[key] = head->next;

        return mp[key]->value;
    }

    void put(int key, int value)
    {
        if (mp.size() < cap)
        {
            if (!mp.count(key))
            {
                Node *newNode = new Node(key, value);

                insertAtHead(newNode, head);
                mp[key] = head->next;
            }
            else
            {
                Node *address = mp[key];
                deleteNode(address);

                address->value = value;

                insertAtHead(address, head);

                mp[key] = head->next;
            }
        }
        else if (mp.size() == cap)
        {
            if (!mp.count(key))
            {
                Node *nodeToDelete = tail->prev;
                deleteNode(nodeToDelete);

                mp.erase(nodeToDelete->key);

                nodeToDelete->key = key;
                nodeToDelete->value = value;

                insertAtHead(nodeToDelete, head);
                mp[key] = head->next;
            }
            else
            {
                Node *address = mp[key];
                deleteNode(address);

                address->value = value;

                insertAtHead(address, head);

                mp[key] = head->next;
            }
        }
    }
};
