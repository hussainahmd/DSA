#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next, *prev;

    Node(int item){
        data = item;
        next = NULL;
        prev = NULL;
    }
};

void addFirst(Node *&head, int item){
    Node *node = new Node(item);
    if(head == NULL){
        head = node;
        node->next = NULL;
        return;
    }
    node->next = head;
    head->prev = node;
    head = node;
}

void addLast(Node *&head, int item){
    Node *node = new Node(item);
    if(head == NULL){
        head = node;
        node->next = NULL;
        return;
    }
    Node *p = head;
    while(p->next != NULL)
        p = p->next;
    
    p->next = node;
    node->prev = p;
}

void addPos(Node *&head, int k, int item){
    if(k < 0){
        cout << "Invalid position\n";
        return;
    }
    if(k == 0){
        addFirst(head, item);
        return;
    }
    Node *p = head;
    Node *node = new Node(item);
    while(p != NULL && --k){
        p = p->next;
    }
    if(k == 0){
        node->next = p->next;
        node->prev = p;
        p->next = node;
    }else
        cout << "Position does not exist\n";
}

int removeFirst(Node *&head){
    if(head == NULL){
        cout << "Error! List is empty\n";
        return -404;
    }
    Node *p = head;
    int data = p->data;
    if(head->next == NULL)
        head = NULL;
    else
        head = head->next;

    delete p;
    return data;
}

int removeLast(Node *&head){
    if(head == NULL){
        cout << "Error! List is empty\n";
        return -404;
    }
    Node *p = head;
    if(p->next == NULL)
        return removeFirst(head);

    while(p->next->next != NULL)
        p = p->next;
    
    int data = p->next->data;
    delete(p->next);
    p->next = NULL;
    return data;
}

int removePos(Node *&head, int k){
    if(head == NULL){
        cout << "Error! list is empty\n";
        return -404;
    }
    if(k < 0){
        cout << "Invalid position\n";
        return -404;
    }
    if(k == 0)
        return removeFirst(head);

    Node *p = head, *q = NULL;
    while(p->next != NULL && k--){
        q = p;
        p = p->next;
    }
    if(k == 0)
        return removeLast(head);
    
    if(k == -1){
        q->next = p->next;
        p->next->prev = q;
        int data = p->data;
        delete p;
        return data;
    }
    cout << "Position does not exist\n";
    return -404;
}

void display(Node *&head){
    if(head == NULL)
        cout << "List is empty\n";
    else{
        Node *i = head;
        int size = 1;
        cout << "[NULL <-- ";
        while(i->next != NULL){
            cout << i->data << " <--> ";
            i = i->next;
            size++;
        }
        cout << i->data << " --> NULL] (Size : " << size << ")\n\n";
    }
}

int main(){

    Node *l1 = NULL;
    Node *l2 = NULL;

    cout << "\nAdd first & last : ";
    addFirst(l1, 1);
    addLast(l1, 2);
    display(l1);

    cout << "Add last & at position : ";
    addLast(l1, 3);
    addLast(l1, 4);
    addPos(l1,4,5);
    addPos(l1,5,6);
    display(l1);

    cout << "Remove last : ";
    removeLast(l1);
    display(l1);

    cout << "Remove after 3rd pos : ";
    removePos(l1, 3);
    display(l1);
}