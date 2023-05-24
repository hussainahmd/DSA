#include <iostream>
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

void display(Node *&head)
{
    if (head == NULL)
        cout << "head is empty\n";
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

void sortList(Node *&head)
{
    Node *p = head, *q;

    while (p != NULL)
    {
        q = p->next;

        while (q != NULL)
        {
            if (p->data > q->data)
            {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
}

bool isPrimeNum(int n)
{
    if (n <= 1)
        return false;
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
}

void findPrime(Node *&head)
{
    Node *p = head;
    while (p != NULL)
    {
        if (isPrimeNum(p->data))
        {
            cout << p->data << "  ";
        }
        p = p->next;
    }
    cout << "\n";
}

void merge(Node *list1, Node *list2) //merge list1 with list2
{
    if (list1 == NULL && list2 == NULL)
    {
        cout << "Error! Lists are empty\n";
        return;
    }
    if (list1 == NULL)
    {
        list1 = list2;
        return;
    }
    if (list2 == NULL)
    {
        return; // return nothing, keep list1
    }

    Node *p = list1;
    while (p->next != NULL)
        p = p->next;

    p->next = list2;
}

int main()
{
    Node *l1 = NULL;
    Node *l2 = NULL;

    // addLast(l1, 7);
    // addLast(l1, 2);
    // addLast(l1, 9);
    // addLast(l1, 6);
    // addLast(l1, 3);
    // addLast(l1, 1);

    cout << "\nList1 unsorted : ";
    display(l1);

    cout << "List1 sorted : ";
    sortList(l1);
    display(l1);

    cout << "Prime numbers in List1 : ";
    findPrime(l1);

    cout << "\n";

    addLast(l2, 6);
    addLast(l2, 2);
    addLast(l2, 2);
    addLast(l2, 3);
    addLast(l2, 1);
    addLast(l2, 4);

    cout << "List2 : ";
    display(l2);

    cout << "List1 after merging with List2:\n";
    merge(l1, l2);
    display(l1);
}
