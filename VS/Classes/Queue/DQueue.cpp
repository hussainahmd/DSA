#include<iostream>
using namespace std;

template <class T>
class DQueue{

    public:
        T* items;
        int front, rear, size;

        DQueue(int);
        ~DQueue();

        bool isEmpty();
        bool isFull();

        void insertFront(int);
        void insertRear(int);
        T removeFront();
        T removeRear();

        void display();
        void display2();
};

template <class T>
DQueue<T>::DQueue(int s){
    if(s <= 0)
        throw invalid_argument("Invalid input for size!");
    front = -1;
    rear = -1;
    size = s;
    items = new T[s]();
}

template <class T>
DQueue<T>::~DQueue(){
    delete items;
}

template <class T>
bool DQueue<T>::isFull(){
    if(front == 0 && rear == size - 1 || front == rear + 1)
        return true;
    return false;
}

template <class T>
bool DQueue<T>::isEmpty(){
    if(front == -1)
        return true;
    return false;
}

template <class T>
void DQueue<T>::insertFront(int item){
    if(isFull())
        cout << "Error! Queue is full\n";
    else{
        if(isEmpty()){
            front = 0;
            rear = 0;
        }
        else if(front == 0)
            front = size - 1;
        else{
            front--;
        }
        items[front] = item;
        cout << "Item inserted at Front: " << item << "\n";
    }
}

template <class T>
void DQueue<T>::insertRear(int item){
    if(isFull())
        cout << "Error! Queue is full\n";
    else{
        if(isEmpty())
            front = 0;

        rear = (rear + 1) % size;
        items[rear] = item;
        cout << "Item inserted at Rear: " << item << "\n";
    }
}

template <class T>
T DQueue<T>::removeFront(){
    if(isEmpty()){
        cout << "Error! Queue is empty\n";
        return -1;
    }
    else{
        T temp = items[front];items[front]=0;
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % size;
        
        cout << "Item removed from front: " << temp << "\n";
        return temp;
    }
}

template <class T>
T DQueue<T>::removeRear(){
    if(isEmpty()){
        cout << "Error! Queue is empty\n";
        return -1;
    }
    else{
        T temp = items[rear]; items[rear]=0;
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else if(rear == 0)
            rear = size - 1;
        else
            rear--;
    
        cout << "Item removed from rear: " << temp << "\n";
        return temp;
    }
}

template <class T>
void DQueue<T>::display(){
    if(isEmpty()){
        cout << "Error! Queue is empty\n";
        return;
    }
    cout << "\nFront -> " << front;
    cout << "\nItems : ";
    for(int i = 0; i < size; i++){
        cout << items[i] << " ";
    }
    cout << "\nRear -> " << rear << "\n\n";
}
template <class T>
void DQueue<T>::display2(){
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
    DQueue<int> q(5);
    
    q.insertFront(1);
    q.insertRear(4);
    q.insertFront(3);
    q.insertFront(2);
    q.insertRear(5);

    q.insertRear(11);
    q.insertFront(21);

    q.display();
    q.display2();

    q.removeFront();
    q.display();

    q.removeRear();
    q.display();
    q.display2();

    q.insertRear(11);
    q.insertRear(12);
    q.display();
}