#include <bits/stdc++.h>///////////////
using namespace std;

struct Node
{
    int data;
    Node *next = NULL;

    Node(int item)
    {
        data = item;
    }
};

//**************************************************
void addLast(Node *&head, int item);
void display(Node *&head);
void removeNodeIfRightGreater(Node *head);
//**************************************************

int main()
{
    srand(67);
    Node *list = NULL;

    // insert 30 random values
    for (int i = 0; i < 30; i++)
    {
        int x = rand() % 67 + 1;
        addLast(list, x);
    }
    cout << "\nList before removing all nodes that have greater value on right side : \n";
    display(list);

    removeNodeIfRightGreater(list);

    cout << "List after removing all nodes that have greater value on right side : \n";
    display(list);

    return 0;
}

void addLast(Node *&head, int item)
{
    Node *node = new Node(item);
    if (head == NULL)
    {
        head = node;
        return;
    }
    Node *p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = node;
}

void removeNodeIfRightGreater(Node *head)
{
    for (Node *i = head; i != NULL;)
    {
        int value = i->data;
        bool found = false;

        for (Node *j = i->next; j != NULL; j = j->next)
        {
            if (j->data > value)
            {
                found = 1;
                break;
            }
        }
        if (found)
        {
            // delete node i
            Node *temp = i->next;
            i->data = i->next->data;
            i->next = i->next->next;
            delete temp;
        }
        else
        {
            i = i->next;
        }
    }
}

void display(Node *&head)
{
    if (head == NULL)
        cout << "List is empty\n";
    else
    {
        Node *i = head;
        int size = 0;
        cout << "[";
        while (i != NULL)
        {
            cout << i->data << " -> ";
            i = i->next;
            size++;
        }
        cout << "NULL] (Size : " << size << ")\n\n";
    }
}
