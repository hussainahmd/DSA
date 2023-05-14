#ifndef LinkedList_H
#define LinkedList_H

template <class T>
class LinkedList{
    public:
        struct Node{
            T data;
            Node *next;

            Node(T item){
                data = item;
                next = NULL;
            }
        };

        Node *head, *tail;
        int SIZE;
        LinkedList();

        void addNodeFirst(Node* node);
        void addNodeLast(Node* node);
        void addNodePos(int pos, Node* node);//(pos)-> 0 means first, =size means last

        void addFirst(T item);
        void addLast(T item);
        void addPos(int pos, T item);//pos^, item
        void addAfter(T key, T item);//key, item
        void addBefore(T key, T item);//key, item

        T removeFirst();
        T removeLast();
        T removePos(int pos);//as index
        void removeKey(T key);

        Node* get(int pos); //as index
        Node* getFirst();
        Node* getLast();
        Node* getMid();
        Node* getKthFromLast(int pos);//start from last (not index)
        Node* getKthFromLast2(int pos);//start from last (not index)

        T set(int pos, T item);//as index
        T setFirst(T item);
        T setLast(T item);

        void reverseItr();
        void reverseRec();

        void display();
        bool isEmpty();
        void clear(); //removes all nodes
        void refresh();
        void sort();

        int size(){
            return SIZE;
        };

    private:
        Node* reverseRecUtil(Node *, Node *); //previous node , current node
        Node* getKthFromLastUtil(Node*, int&);

};

#endif