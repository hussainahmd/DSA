#include<iostream>
using namespace std;

template <class T>
class Queue{
    T* items;
    int front, rear, size;
    public:
        Queue(int s);
        ~Queue();
    
    bool isFull();
    bool isEmpty();
    void enQueue(T item);
    T deQueue();
    void display();
};

template <class T>
Queue<T>::Queue(int s){
    if(s <= 0)
        throw invalid_argument("Invalid input for size!");

    front = -1;
    rear = -1;
    size = s;
    items = new T[s]();
}

template <class T>
Queue<T>::~Queue(){
    delete items;
}

template <class T>
bool Queue<T>::isFull(){
    if(front == 0 && rear == size - 1)
        return true;
    return false;
}

template <class T>
bool Queue<T>::isEmpty(){
    if(front == -1)
        return true;
    return false;
}

template <class T>
void Queue<T>::enQueue(T item){
    if(isFull())
        cout << "Error! Queue is full\n";
    else{
        if(rear == -1) //could also use front == -1
            front = 0;
        rear++;
        items[rear] = item;
        cout << "Item inserted : " << item << "\n";
    }
}

template <class T>
T Queue<T>::deQueue(){
    if(isEmpty()){
        cout << "Error! Queue is empty\n";
        return -1;
    }
    else{
        T temp = items[front];
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else
            front++;
        
        cout << "Item removed : " << temp << "\n";
        return temp;
    }
}

template <class T>
void Queue<T>::display(){
    if(isEmpty())
        cout << "Error! Queue is empty\n";
    else{
        
        cout << "Items : ";
        for(int i = front; i <= rear; i++)
            cout << items[i] << " ";
        cout << "\n";
    }
}

int main(){

    Queue<int> q(2);

    q.enQueue(100);
    q.enQueue(900);
    q.enQueue(500);

    q.display();
    q.deQueue();
    q.display();

    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();

    return 0;
}