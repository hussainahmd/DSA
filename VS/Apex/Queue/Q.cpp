#include<bits/stdc++.h>
using namespace std;

#define size 5
int items[size], front = -1, rear = -1;

bool isEmpty(){
    if(front == -1)
        return true;
    return false;
}

bool isFull(){
    if(rear == size - 1)
        return true;
    return false;
}

void enQ(int item){
    if(isFull()){
        cout << "Error! Queue is full\n";
        return;
    }

    if(isEmpty())
        front = 0;

    rear++;
    items[rear] = item;
    cout << "Item inserted : " << item << "\n";
}

int deQ(){
    if(isEmpty()){
        cout << "Error! Queue is empty\n";
        return -1;
    }
    int temp = items[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
    else
        front ++;
    
    cout << "Item removed : " << temp << "\n";
    return temp;
}

void display(){
    if(isEmpty()){
        cout << "Error! Queue is empty\n";
        return;
    }
    cout << "Items : ";
        for(int i = front; i <= rear; i++)
            cout << items[i] << " ";
        cout << "\n";
}

int main(){
    deQ();
    enQ(1);enQ(2);enQ(3);enQ(4);enQ(5);enQ(1);
    display();
    deQ();//deQ();//deQ();deQ();deQ();
    display();
    cout << front << "\n" << rear << "\n" << rear-front+1;
}