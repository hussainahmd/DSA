#include <bits/stdc++.h>
using namespace std;

#define size 10
int items[size], top = -1;

bool isEmpty()
{
    if (top == -1)
        return true;
    return false;
}

bool isFull()
{
    if (top == size - 1)
        return true;
    return false;
}

void push(int item)
{
    if (isFull())
    {
        cout << "Error! Stack is full\n";
        return;
    }
    top++;
    items[top] = item;
    cout << "Item inserted : " << item << "\n";
}

int pop()
{
    if (isEmpty())
    {
        cout << "Error! Stack is empty\n";
        return -1;
    }
    int temp = items[top];
    top--;
    cout << "Item removed : " << temp << "\n";
    return temp;
}

int peek()
{
    if (isEmpty())
    {
        cout << "Error! Stack is empty\n";
        return -1;
    }
    return items[top];
}

void display()
{
    if (isEmpty())
    {
        cout << "Error! Stack is empty\n";
        return;
    }
    cout << "Stack : ";
    for (int i = top; i >= 0; i--)
    {
        cout << items[i] << " ";
    }
    cout << "\n";
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    display();

    pop();
    display();
    cout << peek();
}