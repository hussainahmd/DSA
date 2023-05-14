//DSA sp22-bcs-067
#include<iostream>
using namespace std;

template <class T>
class DoubleStack{
    public:
        T* items;
        int top1;
        int top2;
        int stackSize;

        DoubleStack(int s);
        ~DoubleStack();

        bool isEmptyS1();
        bool isEmptyS2();
        bool isFull();

        void pushS1(T item);
        T popS1();
        void displayS1();

        void pushS2(T item);
        T popS2();
        void displayS2();

};

template <class T>
DoubleStack<T>::DoubleStack(int s){
    if(s <= 0)
        throw invalid_argument("Invalid input for size!");

    stackSize = s;
    top1 = -1;
    top2 = stackSize;
    items = new T[s]();
}

template <class T>
DoubleStack<T>::~DoubleStack(){
    delete items;
}

template <class T>
void DoubleStack<T>::pushS1(T item){
    if(isFull())
        throw runtime_error("Error! Stack overflowed");
    else{
        top1++;
        items[top1] = item;
        cout << "Item pushed on Stack1 : " << item << "\n";
    }
}

template <class T>
void DoubleStack<T>::pushS2(T item){
    if(isFull())
        throw runtime_error("Error! Stack overflowed");
    else{
        top2--;
        items[top2] = item;
        cout << "Item pushed on Stack2 : " << item << "\n";
    }
}

template <class T>
T DoubleStack<T>::popS1(){
    if(isEmptyS1())
        throw runtime_error("Error! Stack1 is empty");
    else{
        T temp = items[top1];
        top1--;
        cout << "Item popped from Stack1 : " << temp << "\n";
    }
}

template <class T>
T DoubleStack<T>::popS2(){
    if(isEmptyS2())
        throw runtime_error("Error! Stack2 is empty");
    else{
        T temp = items[top2];
        top2++;
        cout << "Item popped from Stack2 : " << temp << "\n";
    }
}

template <class T>
void DoubleStack<T>::displayS1(){
    if(isEmptyS1())
        throw runtime_error("Error! Stack1 is empty");
    else{
        for(int i = top1; i >= 0; i--)
            cout << items[i] << " ";
        cout << "\n";
    }
}

template <class T>
void DoubleStack<T>::displayS2(){
    if(isEmptyS2())
        throw runtime_error("Error! Stack2 is empty");
    else{
        for(int i = top2; i < stackSize; i++)
            cout << items[i] << " ";
        cout << "\n";
    }
}

template <class T>
bool DoubleStack<T>::isEmptyS1(){
    if(top1 <= -1)
        return true;
    return false;
}

template <class T>
bool DoubleStack<T>::isEmptyS2(){
    if(top2 >= stackSize)
        return true;
    return false;
}

template <class T>
bool DoubleStack<T>::isFull(){
    if(top1 == top2 - 1)
        return true;
    return false;
}

int main(){
    try{
        DoubleStack<int> s(5);
        cout << s.top1 << " " << s.top2 << " \n";

        s.pushS2(11);
        s.pushS2(22);
        s.pushS2(33);
        s.pushS2(44);
        s.pushS2(55);
        //s.pushS1(66);
        s.displayS2();
        cout <<"A: "<< s.top1 << " B: " << s.top2 << "\n";
        s.pushS2(1);
        s.displayS2();
        s.pushS2(2);
        s.pushS2(3);
        s.pushS2(4);
        s.pushS2(5);
        s.pushS2(6);

        cout << endl;
        s.displayS1();
        s.displayS2();
        cout << endl;

        s.popS2();
        s.popS2();
        s.popS1();
        s.popS1();

        cout << endl;
        s.displayS1();
        s.displayS2();

    }catch(exception &e){
        cout << e.what() << "\n\n";
    }
}
