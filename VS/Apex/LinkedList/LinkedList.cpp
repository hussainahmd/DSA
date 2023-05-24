#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int item){
        data = item;
        next = NULL;
    }
};

void addFirst(Node *&head, int item){
    Node *node = new Node(item);
    if(head == NULL){
        head = node;
        return;
    }
    node->next = head;
    head = node;
}

void addLast(Node *&head, int item){
    Node *node = new Node(item);
    if(head == NULL){
        head = node;
        return;
    }
    Node *p = head;
    while(p->next != NULL)
        p = p->next;
    
    p->next = node;
}

void addSorted(Node *&head, int item){
    Node *node = new Node(item);
    if(head == NULL){
        head = node;
        return;
    }
    Node *p = head;
    if(item <= p->data){
        node->next = head;
        head = node;
        return;
    }
    while(p->next != NULL){
        if(item <= p->next->data){
            node->next = p->next;
            p->next = node;
            return;
        }
        p = p->next;
    }
    p->next = node;
}


void addPos(Node *&head, int k, int item){//add after pos
    if(k < 0){
        cout << "Invalid position\n";
        return;
    }
    Node *p = head;
    Node *node = new Node(item);
    if(k == 0){
        addFirst(head, item);
        return;
    }
    while(p != NULL && --k){
        p = p->next;
    }
    if(k == 0){
        node->next = p->next;
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

void removeDupes(Node *&head){
    if(head == NULL){
        cout << "Error! List is empty\n";
        return;
    }
    Node *o, *p = head, *q;

    while(p != NULL){
        q = p->next;
        o = p;

        while(q != NULL){
            if(p->data == q->data){
                o->next = q->next;
                delete q;
                q = o;
            }
            o = q;
            q = q->next;
        }
        p = p->next;
    }
}

int removePos(Node *&head, int k){//node after pos
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

    Node *p = head, *q;
    while(p->next != NULL && --k){
        p = p->next;
    }
    if(k == 0){
        q = p->next;
        int data = q->data;
        p->next = q->next;
        delete q;
        return data;
    }else
        cout << "Position does not exist\n";
    
}

void display(Node *&head){
    if(head == NULL)
        cout << "List is empty\n";
    else{
        Node *i = head;
        int size = 0;
        cout << "[";
        while(i != NULL){
            cout << i->data << " -> ";
            i = i->next;
            size++;
        }
        cout << "NULL] (Size : " << size << ")\n\n";
    }
}

void swapPairByLink(Node *&head){
    if(head == NULL){
        cout << "Error! list is empty\n";
        return;
    }
    if(head->next == NULL)
        return;

    Node *o, *p = head, *q = p->next;
    head = q;
    while(p != NULL){
        p->next = q->next;
        q->next = p;

        o = p;
        p = p->next;

        if(p == NULL)
            return;

        q = p->next;

        if(q == NULL)
            return;

        o->next = q;
    }
}

void sortList(Node *&head){
    Node *p = head, *q;
    
    while(p != NULL){
        
        q = p->next;

        while(q != NULL){

            if(p->data > q->data){
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
    
}

bool isPrimeNum(int n){

    if(n <= 1)
        return false;
    else{
        for(int i = 2; i < n; i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }
}

void findPrime(Node *&head){
    Node *p = head;
    while(p != NULL){
        if(isPrimeNum(p->data)){
            cout << p->data << "  ";
        }
        p = p->next;
    }
    cout << "\n";
}

Node* merge(Node *list1, Node *list2){
    if(list1 == NULL && list2 == NULL){
        cout << "Error! Lists are empty\n";
        return NULL;
    }
    if(list1 == NULL)
        return list2;

    if(list2 == NULL)
        return list1;
    
    Node *p = list1;
    while(p->next != NULL)
        p = p->next;
    
    p->next = list2;
    return list1;
}

void mergeAlternate(Node *&list1, Node *&list2)
{
    Node *current1 = list1, *next1;
    Node *current2 = list2, *next2;

    while (current1 != NULL && current1 != NULL)
    {
        next1 = current1->next;
        next2 = current2->next;

        current1->next = current2;
        current2->next = next1;

        current1 = next1;
        current2 = next2;

    }
    list2 = current2;
}

int main(){
    Node *l1 = NULL;
    Node *l2 = NULL;

    addLast(l1, 3);addLast(l1, 6);
    addLast(l1, 5);addLast(l1, 4);
    addLast(l1, 2);addLast(l1, 6);
    addLast(l1, 5);addLast(l1, 4);
    addLast(l1, 1);addLast(l1, 4);

    cout << "\nList1 unsorted : ";
    display(l1);

    cout << "List1 sorted : ";
    sortList(l1);
    display(l1);

    cout << "List1 after rem dupes : ";
    removeDupes(l1);
    display(l1);

    cout << "List2 : ";
    addSorted(l2,11);addSorted(l2,12);
    addSorted(l2,1);addSorted(l2,4);
    addSorted(l2,8);addSorted(l2,5);
    addSorted(l2,2);addSorted(l2,9);
    display(l2);

    cout << "List2 after swap pair : ";
    swapPairByLink(l2);
    display(l2);

    cout << "remove pos : ";
    removePos(l2, 8);
    display(l2);
    
}