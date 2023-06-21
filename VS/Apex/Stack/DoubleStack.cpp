#include <bits/stdc++.h>
using namespace std;

#define size 5
int items[size], top1 = -1, top2 = size;

bool isEmptyS1()
{
    if (top1 == -1)
        return true;
    return false;
}

bool isEmptyS2()
{
    if (top2 == size)
        return true;
    return false;
}

bool isFull()
{
    if (top1 == top2 - 1)
        return true;
    return false;
}

void pushS1(int item)
{
    if (isFull())
    {
        cout << "Error! Stack1 is full\n";
        return;
    }
    top1++;
    items[top1] = item;
    cout << "Item pushed on Stack1 : " << item << "\n";
}

void pushS2(int item)
{
    if (isFull())
    {
        cout << "Error! Stack2 is full\n";
        return;
    }
    top2--;
    items[top2] = item;
    cout << "Item pushed on Stack2 : " << item << "\n";
}

int popS1()
{
    if (isEmptyS1())
    {
        cout << "Error! Stack1 is empty\n";
        return -1;
    }
    int temp = items[top1];
    top1--;
    cout << "Item popped from Stack1 : " << temp << "\n";
    return temp;
}

int popS2()
{
    if (isEmptyS2())
    {
        cout << "Error! Stack2 is empty\n";
        return -1;
    }
    int temp = items[top2];
    top2++;
    cout << "Item popped from Stack2 : " << temp << "\n";
    return temp;
}

void displayS1()
{
    if (isEmptyS1())
    {
        cout << "Error! Stack1 is empty\n";
        return;
    }
    cout << "Stack1 : ";
    for (int i = top1; i >= 0; i--)
        cout << items[i] << " ";
    cout << "\n";
}

void displayS2()
{
    if (isEmptyS2())
    {
        cout << "Error! Stack2 is empty\n";
        return;
    }
    cout << "Stack2 : ";
    for (int i = top2; i < size; i++)
        cout << items[i] << " ";
    cout << "\n";
}

int main()
{
    pushS1(1);
    pushS1(2);
    pushS1(3);
    displayS1();
    pushS2(3);
    pushS2(4);
    displayS2();
    pushS2(1);
}