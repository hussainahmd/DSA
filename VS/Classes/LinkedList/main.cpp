#include<iostream>
#include"LinkedList.h"
#include"LinkedList.cpp"
using namespace std;

int main(){

    LinkedList<int> list;
    list.addFirst(5);
    list.addFirst(4);
    list.addLast(6);
    list.addLast(7);
    list.addLast(8);
    list.addFirst(3);
    list.display();

    LinkedList<int> l2;
    l2.addFirst(15);
    l2.addFirst(14);
    l2.addFirst(13);
    l2.addLast(16);
    l2.display();

    l2.removePos(3);
    l2.display();

    // LinkedList<int>::Node*n = list.get(4);
    // LinkedList<int>::Node x(100);
    // l2.addNodePos(0,n);
    // l2.addNodePos(6,&x);

    // l2.display();
    // if(l2.tail != NULL)
    //     cout << l2.head->data << "<-H " << " || " << l2.tail->data << "<-T \n\n";

    // list.display();
    // if(l2.tail != NULL)
    //     cout << list.head->data << "<-H " << " || " << list.tail->data << "<-T \n\n";

    // list.refresh();
    // list.display();
    // if(l2.tail != NULL)
    //     cout << list.head->data << "<-H " << " || " << list.tail->data << "<-T \n\n";

    cout << endl;
}