#include <bits/stdc++.h>
using namespace std;

struct MinHeap
{
    int *tree;
    int capacity;
    int size = 0;

    MinHeap(int c)
    {
        tree = new int[c];
        capacity = c;
    }
};

#define Q_size 30
struct Queue
{
    int items[Q_size];
    int front = -1, rear = -1;
};

//************************* MinHeap ***************************
void shift_up(MinHeap *ht, int currentIndex);
void shift_down(MinHeap *ht, int currentIndex);
void insert(MinHeap *ht, int item);
int remove(MinHeap *ht);
void display(MinHeap *ht);
//*************************** Queue ***************************
bool isEmpty(Queue *q);
bool isFull(Queue *q);
void enQ(Queue *q, int item);
int deQ(Queue *q);
//********************************************************

int main()
{
    srand(67);
    MinHeap *ht = new MinHeap(30);
    // insert 30 random values
    for (int i = 0; i < 30; i++)
    {
        int x = rand() % 67 + 1;
        insert(ht, x);
    }
    cout << "Unsorted Heap : ";
    display(ht);

    // remove the root node from from MinHeap and enQueue it in a queue
    Queue *q = new Queue;
    for (int i = 0; i < 30; i++)
    {
        enQ(q, remove(ht));
    }

    // deQueue from the queue and print in ascending order
    cout << "Sorted Heap : ";
    for (int i = 0; i < 30; i++)
    {
        cout << deQ(q) << " ";
    }
    cout << "\n";

    return 0;
}

//********************** MinHeap functions ********************

void shift_down(MinHeap *ht, int currentIndex)
{
    int leftChildIndex = 2 * currentIndex + 1;
    int rightChildIndex = 2 * currentIndex + 2;

    int minIndex = currentIndex;

    if (leftChildIndex < ht->size && ht->tree[leftChildIndex] < ht->tree[minIndex])
    {
        minIndex = leftChildIndex;
    }

    if (rightChildIndex < ht->size && ht->tree[rightChildIndex] < ht->tree[minIndex])
    {
        minIndex = rightChildIndex;
    }

    if (minIndex != currentIndex)
    {
        swap(ht->tree[currentIndex], ht->tree[minIndex]);
        shift_down(ht, minIndex);
    }
}

void shift_up(MinHeap *ht, int currentIndex)
{
    while (currentIndex > 0)
    {
        int parentIndex = (currentIndex - 1) / 2;

        if (ht->tree[currentIndex] < ht->tree[parentIndex])
        {
            // swap
            int temp = ht->tree[currentIndex];
            ht->tree[currentIndex] = ht->tree[parentIndex];
            ht->tree[parentIndex] = temp;

            // shift current to the parent and check again
            currentIndex = parentIndex;
        }
        else
            break;
    }
}

void insert(MinHeap *ht, int item)
{
    if (ht->size == ht->capacity)
    {
        cout << "Overflowed!\n";
        return;
    }
    int currentIndex = ht->size;
    ht->tree[currentIndex] = item;
    ht->size++;

    shift_up(ht, currentIndex);
}

int remove(MinHeap *ht)
{
    if (ht->size == 0)
    {
        cout << "Tree is empty!\n";
        return -404;
    }
    int removedNode = ht->tree[0];
    ht->tree[0] = ht->tree[ht->size - 1];
    ht->tree[ht->size - 1] = removedNode;
    ht->size--;

    shift_down(ht, 0);

    return removedNode;
}

void display(MinHeap *ht)
{
    if (ht->size < 1)
    {
        cout << "Tree is empty!\n";
        return;
    }
    for (int i = 0; i < ht->size; i++)
    {
        cout << ht->tree[i] << " ";
    }
    cout << "\n\n";
}

//********************** Queue functions ********************

bool isEmpty(Queue *q)
{
    if (q->front == -1)
        return true;
    return false;
}

bool isFull(Queue *q)
{
    if (q->rear == Q_size - 1)
        return true;
    return false;
}

void enQ(Queue *q, int item)
{
    if (isFull(q))
    {
        cout << "Error! Queue is full\n";
        return;
    }

    if (isEmpty(q))
        q->front = 0;

    q->rear++;
    q->items[q->rear] = item;
}

int deQ(Queue *q)
{
    if (isEmpty(q))
    {
        cout << "Error! Queue is empty\n";
        return -1;
    }
    int temp = q->items[q->front];
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
        q->front++;

    return temp;
}
