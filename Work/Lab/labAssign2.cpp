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

void mergeAlternate(Node *&list1, Node *&list2)
{
    Node *current1 = list1, *q;
    Node *current2 = list2, *b;

    while (current1 != NULL && current2 != NULL)
    {
        q = current1->next;
        b = a->next;

        current1->next = a;
        a->next = q;

        current1 = q;
        a = b;
    }
    list2 = a;
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

int main()
{
    Node *l1 = NULL;
    Node *l2 = NULL;

    addLast(l1, 5);
    addLast(l1, 7);
    // addLast(l1, 17);
    // addLast(l1, 13);
    // addLast(l1, 11);

    addLast(l2, 12);
    addLast(l2, 10);
    addLast(l2, 2);
    addLast(l2, 4);
    addLast(l2, 6);

    cout << "List1 : ";
    display(l1);
    cout << "List2 : ";
    display(l2);

    mergeAlternate(l1, l2);
    cout << "List1 after merging : ";
    display(l1);

    if (l2 == NULL)
    {
        cout << "List2 is empty\n";
    }
    else
    {
        cout << "List2 : ";
        display(l2);
    }
}