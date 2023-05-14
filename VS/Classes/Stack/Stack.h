#include<iostream>
#include <stdexcept>

using namespace std;

template <class T>
class Stack{
    
    public:
        T* items;
        int top, stackSize;
        Stack();
        Stack(int s);
        ~Stack();
        
        void push(T item);
        T pop();
        T peek();
        void printStack();
        void display();
        bool isEmpty();
        bool isFull();

};

template <class T>
Stack<T>::Stack(){
    top = -1;
    stackSize = 20;
    items = new T[stackSize]();
}

template <class T>
Stack<T>::Stack(int s){
    if(s <= 0)
        throw invalid_argument("Invalid input for size!");

    top = -1;
    stackSize = s;
    items = new T[s]();
}

template <class T>
Stack<T>::~Stack(){
    delete items;
}

template <class T>
bool Stack<T>::isFull(){
    if(top == stackSize - 1)
        return true;
    return false;
}

template <class T>
bool Stack<T>::isEmpty(){
    if(top == -1)
        return true;
    return false;
}

template <class T>
void Stack<T>::push(T item){
    if(isFull())
        throw runtime_error("Error! Stack overflowed");
    else{
        top++;
        items[top] = item;
    }
}

template <class T>
T Stack<T>::pop(){
    if(isEmpty())
        throw runtime_error("Error! Stack is empty");
    else{
        T temp = items[top];
        //items[top] = 'z';
        top--;
        return temp;
    }
}

template <class T>
T Stack<T>::peek(){
    if(top >= 0)
        return items[top];
}

template <class T>
void Stack<T>::printStack(){
    cout << "Contents of the stack : ";
    for(int i = 0; i < stackSize; i++){
        cout << items[i] << " ";
    }
    cout << endl;
}

template <class T>
void Stack<T>::display(){
    int x = top;
    while(x > -1){
        cout << items[x] << " ";
        x--;
    }
}