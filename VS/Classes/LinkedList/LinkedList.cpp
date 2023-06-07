#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    tail = NULL;
    SIZE = 0;
}

template <class T>
void LinkedList<T>::sort()
{
    Node *p = head;
    T max;
}

template <class T>
void LinkedList<T>::addNodePos(int pos, Node *node)
{
    if (pos < 0)
    {
        cout << "Invalid position\n";
        return;
    }
    if (pos == 0)
    {
        addNodeFirst(node);
        return;
    }
    int x = 1;
    Node *p = head;
    while (p != NULL && --pos)
        p = p->next;

    if (pos == 0)
    {
        Node *q = node;
        while (q->next != NULL)
        {
            x++;
            q = q->next;
        }
        q->next = p->next;
        p->next = node;
        SIZE += x;
    }
    else
        cout << "Position does not exist\n";
}

template <class T>
void LinkedList<T>::addPos(int pos, T item)
{
    if (pos > SIZE || pos < 0)
    {
        cout << "Invalid position OR position does not exist\n";
        return;
    }
    if (pos == 0)
    {
        addFirst(item);
        return;
    }
    if (pos == SIZE)
    {
        addLast(item);
        return;
    }
    Node *node = new Node(item);
    Node *p = head;
    for (int count = 1; true; count++)
    { // no condition needed
        if (count == pos)
        {
            node->next = p->next;
            p->next = node;
            SIZE++;
            return;
        }
        p = p->next;
    }
    /* (if you don't have SIZE variable)
    //OR pos--;
    while(p != NULL && --pos){ //OR pos != 0
        p = p->next; //OR pos--
    }

    if(pos == 0){
        node->next = p->next;
        p->next = node;
    }else
        cout << "Pos does not exist"; */
}

template <class T>
void LinkedList<T>::addNodeFirst(Node *node)
{
    int x = 1;
    Node *p = node;
    while (p->next != NULL)
    {
        x++;
        p = p->next;
    }
    if (isEmpty())
    {
        head = node;
        tail = p;
    }
    else
    {
        p->next = head;
        head = node;
    }
    SIZE += x;
}

template <class T>
void LinkedList<T>::addFirst(T item)
{
    Node *node = new Node(item);
    if (isEmpty())
    {
        head = node;
        tail = node;
    }
    else
    {
        node->next = head;
        head = node;
    }
    SIZE++;
}

template <class T>
void LinkedList<T>::addNodeLast(Node *node)
{
    int x = 1;
    Node *p = node;
    while (p->next != NULL)
    {
        x++;
        p = p->next;
    }
    if (isEmpty())
    {
        head = node;
        tail = p;
    }
    else
    {
        tail->next = node;
        tail = p;
    }
    SIZE += x;
}

template <class T>
void LinkedList<T>::addLast(T item)
{
    Node *node = new Node(item);
    if (isEmpty())
    {
        head = node;
        tail = node;
    }
    else
    {
        tail->next = node;
        tail = tail->next;
    }
    SIZE++;
}

template <class T>
typename LinkedList<T>::Node *LinkedList<T>::getKthFromLast2(int k)
{
    if (isEmpty())
    {
        cout << "List is empty\n";
        return NULL;
    }
    Node *slow = head, *fast = head;
    while (fast != NULL && k--)
        fast = fast->next;

    if (fast != NULL)
    {
        while (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
    else
    {
        cout << "Kth position does not exist\n";
        return NULL;
    }
}

template <class T>
typename LinkedList<T>::Node *LinkedList<T>::getKthFromLast(int k)
{
    if (isEmpty())
    {
        cout << "List is empty\n";
        return NULL;
    }
    if (k <= 0)
    {
        cout << "Error, Invalid value for k\n";
        return NULL;
    }
    Node *p = getKthFromLastUtil(head, k);
    if (k > 1)
    {
        cout << "Kth position does not exist\n";
        return NULL;
    }
    return p;
}

template <class T>
typename LinkedList<T>::Node *LinkedList<T>::getKthFromLastUtil(Node *p, int &k)
{
    if (p->next != NULL)
    {
        Node *node = getKthFromLastUtil(p->next, k);
        k--;
        if (k <= 0)
        {
            return node;
        }
        else
            return p;
    }
    else
        return p;
}

template <class T>
typename LinkedList<T>::Node *LinkedList<T>::getMid()
{
    if (isEmpty())
    {
        cout << "List is empty\n";
        return NULL;
    }
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template <class T>
typename LinkedList<T>::Node *LinkedList<T>::reverseRecUtil(Node *prev, Node *curr)
{
    if (curr != NULL)
    {
        Node *head = reverseRecUtil(curr, curr->next);
        curr->next = prev;
        return head;
    }
    else
        return prev;
}

template <class T>
void LinkedList<T>::reverseRec()
{
    if (isEmpty())
    {
        cout << "List is empty\n";
        return;
    }
    tail = head;
    head = reverseRecUtil(NULL, head);
}

template <class T>
void LinkedList<T>::reverseItr()
{
    if (isEmpty())
    {
        cout << "List is empty\n";
        return;
    }
    // o = previous, p = current, q = next
    Node *o = NULL, *p = head, *q = NULL;
    while (p != NULL)
    {
        q = p->next;
        p->next = o;
        o = p;
        p = q;
    }
    tail = head;
    head = o;
}

template <class T>
T LinkedList<T>::setFirst(T item)
{
    if (isEmpty())
    {
        cout << "List is empty\n";
        return -1;
    }
    T data = head->data;
    head->data = item;
    return data;
}

template <class T>
T LinkedList<T>::setLast(T item)
{
    if (isEmpty())
    {
        cout << "List is empty\n";
        return -1;
    }
    T data = tail->data;
    tail->data = item;
    return data;
}

template <class T>
T LinkedList<T>::set(int pos, T item)
{
    if (isEmpty())
    {
        cout << "List is empty\n";
        return -1;
    }
    if (pos >= SIZE || pos < 0)
    {
        cout << "Invalid position OR position does not exist\n";
        return -1;
    }
    if (pos == 0)
        return setFirst(item);

    if (pos == SIZE - 1)
        return setLast(item);

    T data;
    Node *p = head;
    for (int i = 1; true; i++)
    {
        if (i == pos)
        {
            data = p->data;
            p->data = item;
            return data;
        }
        p = p->next;
    }
}

template <class T>
typename LinkedList<T>::Node *LinkedList<T>::get(int pos)
{
    if (isEmpty())
    {
        cout << "List is empty\n";
        return NULL;
    }
    if (pos >= SIZE || pos < 0)
    {
        cout << "Invalid position OR position does not exist\n";
        return NULL;
    }
    if (pos == 0)
        return head;

    if (pos == SIZE - 1)
        return tail;

    Node *p = head->next;
    T data;
    for (int i = 1; true; i++)
    {
        if (i == pos)
        {
            return p;
        }
        p = p->next;
    }
}

template <class T>
typename LinkedList<T>::Node *LinkedList<T>::getFirst()
{
    if (isEmpty())
    {
        cout << "List is empty";
        return NULL;
    }
    return head;
}

template <class T>
typename LinkedList<T>::Node *LinkedList<T>::getLast()
{
    if (isEmpty())
    {
        cout << "List is empty";
        return NULL;
    }
    return tail;
}

template <class T>
void LinkedList<T>::addBefore(T key, T item)
{
    if (isEmpty())
    {
        cout << "List is empty\n";
        return;
    }
    Node *node = new Node(item);
    Node *p = head;
    if (p->data == key)
    {
        addFirst(item);
        return;
    }
    while (p->next != NULL)
    {
        if (p->next->data == key)
        {
            node->next = p->next;
            p->next = node;
            SIZE++;
            return;
        }
        p = p->next;
    }
    cout << "The given key does not exist\n";
}

template <class T>
void LinkedList<T>::addAfter(T key, T item)
{
    if (isEmpty())
    {
        cout << "List is empty\n";
        return;
    }
    Node *node = new Node(item);
    Node *p = head;
    while (p != NULL)
    {
        if (p->data == key)
        {
            node->next = p->next;
            p->next = node;
            if (node->next == NULL)
                tail = node;
            SIZE++;
            return;
        }
        p = p->next;
    }
    cout << "The given key does not exist\n";
}

template <class T>
T LinkedList<T>::removePos(int pos)
{
    if (isEmpty())
    {
        cout << "Cannot remove! List is empty\n";
        return -1;
    }
    if (pos < 0 || pos >= SIZE)
    {
        cout << "Invalid position OR position does not exist\n";
        return -1;
    }
    if (pos == 0)
        return removeFirst();

    if (pos == SIZE - 1)
        return removeLast();

    Node *p = head;
    Node *q;
    for (int count = 1; true; count++)
    { // no condition needed
        q = p;
        p = p->next;
        if (count == pos)
        {
            q->next = p->next;
            T data = p->data;
            delete p;
            SIZE--;
            return data;
        }
    }
}

template <class T>
void LinkedList<T>::removeKey(T key)
{
    if (isEmpty())
    {
        cout << "Cannot remove! List is empty\n";
        return;
    }
    Node *p = head;
    if (p->data == key)
    {
        removeFirst();
        return;
    }
    while (p->next != NULL && p->next->data != key)
        p = p->next;

    if (p->next == NULL)
        cout << "The given data does not exist\n";
    else
    { // p->next->data == key
        Node *toDel = p->next;
        if (p->next == tail)
        {
            tail = p;
            p->next = NULL;
        }
        else
            p->next = p->next->next;

        delete toDel;
    }
    SIZE--;
}

template <class T>
T LinkedList<T>::removeFirst()
{ // void type might be better
    if (isEmpty())
    {
        cout << "Cannot remove! List is empty\n";
        return -1;
    }
    Node *p = head;
    T data = p->data;
    if (head == tail)
    { // OR if(head->next == NULL)
        head = NULL;
        tail = NULL;
    }
    else
        head = head->next;

    delete p;
    SIZE--;
    return data;
}

template <class T>
T LinkedList<T>::removeLast()
{
    if (isEmpty())
    {
        cout << "Cannot remove! List is empty\n";
        return 0; // error
    }
    Node *p = head;
    T data;
    if (head == tail)
    { // OR if(head->next == NULL)
        data = removeFirst();
        // data = p->data;
        // head = NULL;
        // tail = NULL;
        // delete p;
    }
    else
    {
        while (p->next->next != NULL) // OR != tail
            p = p->next;

        data = p->next->data;
        tail = p;
        delete (p->next);
        p->next = NULL;
        SIZE--;
    }
    return data;
}

template <class T>
void LinkedList<T>::clear()
{
    while (!isEmpty())
    {
        if (!isEmpty())
            cout << "rem : " << head->data << " ";
        removeFirst();
    }
    cout << endl;
}

template <class T>
void LinkedList<T>::refresh()
{
    if (isEmpty())
    {
        cout << "Error! List is empty\n";
        return;
    }
    Node *p = head;
    SIZE = 1;
    while (p->next != NULL)
    {
        p = p->next;
        SIZE++;
    }
    tail = p;
}

template <class T>
void LinkedList<T>::display()
{
    if (isEmpty())
        cout << "List is empty\n";
    else
    {
        Node *i = head;
        cout << "\nList : [";
        while (i != NULL)
        {
            cout << i->data << " -> ";
            i = i->next;
        }
        cout << "NULL] (Size : " << SIZE << ")\n";
    }
}

template <class T>
bool LinkedList<T>::isEmpty()
{
    if (head == NULL) // OR SIZE == 0
        return true;
    return false;
}