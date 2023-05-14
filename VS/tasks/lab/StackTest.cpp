//DSA sp22-bcs-067
#include<iostream>
using namespace std;

#define SIZE 50

struct Stack{
    int items[SIZE]{0};
    int top;
};

void push(Stack *s, int item){
    if(s->top == SIZE - 1)
        cout << "Stack is full\n";
    else{
        s->top++;
        s->items[s->top] = item;
        cout << "Item pushed : " << s->items[s->top] << endl;
    }
}

void pop(Stack *s){
    if(s->top == -1)
        cout << "Stack is empty\n";
    else{
        cout << "Item popped : " << s->items[s->top] << endl;
        s->items[s->top] = 0;
        s->top--;
    }
}

void createEmptyStack(Stack* s){
    s->top = -1;
}

void peek(Stack* s){
    if(s->top >= 0)
        cout << "Top of the stack : " << s->items[s->top] << endl;
    else
        cout << "Stack is empty\n";
}

void printStack(Stack* s){
    cout << "Contents of the stack : ";
    for(int i = 0; i < SIZE; i++){
        cout << s->items[i] << " ";
    }
    cout << endl;
}


int main(){

    Stack S;
    Stack* ptrS = &S;

    createEmptyStack(ptrS);

    push(ptrS, 21);
    push(ptrS, 34);
    push(ptrS, 25);
    push(ptrS, 5);

    peek(ptrS);

    printStack(ptrS);

    push(ptrS, 95);
    push(ptrS, 15);

    printStack(ptrS);

    pop(ptrS);
    pop(ptrS);
    pop(ptrS);

    peek(ptrS);

    printStack(ptrS);
}
