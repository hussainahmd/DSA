#include <bits/stdc++.h>
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

void addFirst(Node *&head, int item)
{
    Node *node = new Node(item);
    if (head == NULL)
    {
        head = node;
        node->next = head;
        return;
    }
    Node *p = head;
    while (p->next != head)
        p = p->next;

    node->next = head;
    head = node;
    p->next = head;
}

void addLast(Node *&head, int item)
{
    Node *node = new Node(item);
    if (head == NULL)
    {
        head = node;
        node->next = head;
        return;
    }
    Node *p = head;
    while (p->next != head)
        p = p->next;

    p->next = node;
    node->next = head;
}

void addPos(Node *&head, int k, int item)
{
    if (k < 0)
    {
        cout << "Invalid position\n";
        return;
    }
    if (k == 0)
    {
        addFirst(head, item);
        return;
    }
    Node *p = head;
    Node *node = new Node(item);

    while (p->next != head && --k)
        p = p->next;

    if (k == 0 || k - 1 == 0)
    {
        node->next = p->next;
        p->next = node;
    }
    else
        cout << "Position does not exist\n";
}

int removeFirst(Node *&head)
{
    if (head == NULL)
    {
        cout << "Error! list is empty\n";
        return -404;
    }
    Node *p = head, *q = head;
    int data = p->data;
    if (p->next == head)
        head = NULL;
    else
    {
        while (q->next != head)
            q = q->next;
        head = head->next;
        q->next = head;
    }
    delete p;
    return data;
}

int removeLast(Node *&head)
{
    if (head == NULL)
    {
        cout << "Error! list is empty\n";
        return -404;
    }
    Node *p = head;
    if (p->next == head)
        return removeFirst(head);

    while (p->next->next != head)
        p = p->next;

    int data = p->next->data;
    delete (p->next);
    p->next = head;
    return data;
}

int removePos(Node *&head, int k)
{
    if (head == NULL)
    {
        cout << "Error! list is empty\n";
        return -404;
    }
    if (k < 0)
    {
        cout << "Invalid position\n";
        return -404;
    }
    if (k == 0)
        return removeFirst(head);

    Node *p = head, *q = NULL;
    //-- even after 0 so k = -1 //doesn't run on last node so k = 0
    while (p->next != head && k--)
    {
        q = p;
        p = p->next;
    }
    if (k == 0)
        return removeLast(head);

    if (k == -1)
    {
        q->next = p->next;
        int data = p->data;
        delete p;
        return data;
    }
    cout << "Position does not exist\n";
    return -404;
}

void display(Node *&head)
{
    if (head == NULL)
        cout << "List is empty\n";
    else
    {
        Node *p = head;
        int size = 0;
        cout << "[";
        while (p->next != head)
        {
            cout << p->data << " -> ";
            p = p->next;
            size++;
        }
        cout << p->data << " -> ";
        size++;
        cout << "NULL] (Size : " << size << ")\n\n";
    }
}

int main()
{

    Node *l1 = NULL;
    Node *l2 = NULL;

    cout << "\nAdd : ";
    addLast(l1, 3);
    addLast(l1, 4);
    addLast(l1, 5);
    addLast(l1, 6);
    addFirst(l1, 2);
    addFirst(l1, 1);
    display(l1);

    cout << "Remove : ";
    removePos(l1, 3);
    removeLast(l1);
    display(l1);
}