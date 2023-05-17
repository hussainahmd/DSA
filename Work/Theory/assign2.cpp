#include <bits/stdc++.h>
using namespace std;

#define SIZE 20
int items[SIZE], front = -1, rear = -1;

bool isEmpty()
{
    if (front == -1)
        return true;
    return false;
}

bool isFull()
{
    if (rear == SIZE - 1)
        return true;
    return false;
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
        front++;

    return temp;
}

void enQx(int item)//with array
{
    if (isFull())
    {
        cout << "Error! Queue is full\n";
        return;
    }
    if (isEmpty())
        front = 0;

    int s = rear - front + 1;
    rear++;
    items[rear] = item;

    for (int i = 0; i < s; i++)
    {
        rear++;
        items[rear] = deQ();
    }

    cout << "Item inserted : " << item << "\n";
}
void enQ(int item)//with vector
{
    if (isFull())
    {
        cout << "Error! Queue is full\n";
        return;
    }
    if (isEmpty())
    {
        front = 0;
        rear++;
        items[rear] = item;
    }
    else
    {
        int s = rear - front + 1;
        vector<int> vec;
        for (int i = 0; i < s; i++)
        {
            vec.push_back(deQ());
        }
        front = 0;
        rear++;
        items[rear] = item;
        for (int i = 0; i < vec.size(); i++)
        {
            rear++;
            items[rear] = vec[i];
        }
    }
    cout << "Item inserted : " << item << "\n";
}

void display()
{
    if (isEmpty())
    {
        cout << "Error! Queue is empty\n";
        return;
    }
    cout << "\nQueue : Front-> ";
    for (int i = front; i <= rear; i++)
        cout << items[i] << " ";
    cout << "<-Rear\n\n";
}

void printArray()
{
    cout << "Array : ";
    for (int i = 0; i < SIZE; i++)
        cout << items[i] << " ";
    cout << "\n";
}

int main()
{
    enQ(1);
    enQ(2);
    display();

    enQ(3);
    enQ(4);
    enQ(5);
    display();

    printArray();
}