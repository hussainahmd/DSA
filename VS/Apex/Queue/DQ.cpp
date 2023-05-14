#include<bits/stdc++.h>
using namespace std;

#define size 5
int items[size], front = -1, rear = -1;

bool isFull(){
    if(front == 0 && rear == size - 1 || front == rear + 1)
        return true;
    return false;
}

bool isEmpty(){
    if(front == -1)
        return true;
    return false;
}

void enQfront(int item){
    if(isFull()){
        cout << "Error! Queue is full\n";
        return;
    }
    if(isEmpty()){
        front = 0;
        rear = 0;
    }
    else if(front == 0)
        front = size - 1;

    else
        front--;

    items[front] = item;
    cout << "Item inserted at Front: " << item << "\n";
}

void enQrear(int item){
    if(isFull()){
        cout << "Error! Queue is full\n";
        return;
    }
    if(isEmpty()){
        front = 0;
        rear = 0;
    }
    rear = (rear + 1) % size;
    items[rear] = item;
    cout << "Item inserted at Rear: " << item << "\n";
}

int deQfront(){
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
        front = (front + 1) & size;

    cout << "Item removed from front: " << temp << "\n";
    return temp;
}

int deQrear(){
    if(isEmpty()){
        cout << "Error! Queue is empty\n";
        return -1;
    }
    int temp = items[rear];
    if(front == rear){
        front == -1;
        rear = -1;
    }
    else if(rear == 0)
        rear = size - 1;
    
    else
        rear--;

    cout << "Item removed from rear: " << temp << "\n";
    return temp;
}

void display(){
    if(isEmpty()){
        cout << "Error! Queue is empty\n";
        return;
    }
    cout << "\nFront -> " << front;
    cout << "\nItems : ";

    for(int i = front; i != rear; i = (i + 1) % size)
        cout << items[i] << " ";

    cout << items[rear] << " ";
    cout << "\nRear -> " << rear << "\n\n";
}

int main(){
    enQfront(1);
    enQrear(4);
    enQfront(3);
    enQfront(2);
    enQrear(5);
    display();

    deQfront();
    deQrear();
    display();
}

