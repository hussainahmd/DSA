#include <bits/stdc++.h>
using namespace std;

#define SIZE 10
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

void enQ(int item)
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
        int queueSize = rear - front + 1;
        vector<int> vec;
        for (int i = 0; i < queueSize; i++)
        {
            vec.push_back(deQ());
        }
        //queue is empty right now
        front = 0;
        rear++;
        items[rear] = item; //insert the new item at front
        for (int i = 0; i < vec.size(); i++)
        {
            //insert all the previous items
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

int main()
{
    enQ(1);
    enQ(2);
    enQ(3);
    enQ(4);
    enQ(5);
    display();

    cout << "Item removed : " << deQ() << "\n";
    cout << "Item removed : " << deQ() << "\n";
    display();

    enQ(6);
    enQ(7);
    display();
}