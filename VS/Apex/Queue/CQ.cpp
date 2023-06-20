#include <bits/stdc++.h>
using namespace std;

#define size 6
int items[size], front = -1, rear = -1;

bool isFull()
{
    if (front == 0 && rear == size - 1 || front == rear + 1)
        return true;
    return false;
}

bool isEmpty()
{
    if (front == -1)
        return true;
    return false;
}

void enQ(int item)
{
    if (isFull())
    {
        cout << "Error! Queue is full\n";
        return;
    }
    if (isEmpty())
        front = 0;

    rear = (rear + 1) % size;
    items[rear] = item;
    cout << "Item inserted : " << item << "\n";
}

int deQ()
{
    if (isEmpty())
    {
        cout << "Error! Queue is empty\n";
        return -1;
    }
    int temp = items[front];
    items[front] = 0;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
        front = (front + 1) % size;

    cout << "Item removed : " << temp << "\n";
    return temp;
}

void sort()
{
    if (isEmpty())
    {
        cout << "Error! Queue is empty\n";
        return;
    }
    for (int i = front; i != rear; i = (i + 1) % size)
    {

        for (int j = i; j != rear; j = (j + 1) % size)
        {

            if (items[i] > items[j])
            {
                int temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "Error! Queue is empty\n";
        return;
    }
    cout << "\nFront -> " << front;
    cout << "\nQueue : ";
    for (int i = front; i != rear; i = (i + 1) % size)
        cout << items[i] << " ";

    cout << items[rear] << " ";
    cout << "\nRear -> " << rear << "\n\n";
}

void print()
{
    if (isEmpty())
    {
        cout << "Error! Queue is empty\n";
        return;
    }
    cout << "\nFront -> " << front;
    cout << "\nArray : ";
    for (int i = 0; i < size; i++)
    {
        cout << items[i] << " ";
    }
    cout << "\nRear -> " << rear << "\n\n";
}

int main()
{
    enQ(2);
    enQ(5);
    enQ(3);
    enQ(4);
    enQ(1);
    display();
    print();
    deQ();
    deQ();
    display();
    print();
    enQ(2);
    enQ(5);
    enQ(6);
    enQ(1);
    display();
    print();
    sort();
    display();
    print();
}