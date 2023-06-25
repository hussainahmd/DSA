#include <bits/stdc++.h>
using namespace std;

struct MaxHeap
{
    int* tree;
    int capacity;
    int size = 0;

    MaxHeap(int c)
    {
        tree = new int[c];
        capacity = c;
    }
};

//*************************************************************

void heapify(MaxHeap *ht, int currentIndex)
{
    int leftChildIndex = 2 * currentIndex + 1;
    int rightChildIndex = 2 * currentIndex + 2;

    int maxIndex = currentIndex;

    if(leftChildIndex < ht->size && ht->tree[leftChildIndex] > ht->tree[maxIndex])
    {
        maxIndex = leftChildIndex;   
    }

    if(rightChildIndex < ht->size && ht->tree[rightChildIndex] > ht->tree[maxIndex])
    {
        maxIndex = rightChildIndex;   
    }

    if(maxIndex != currentIndex)
    {
        swap(ht->tree[currentIndex], ht->tree[maxIndex]);
        heapify(ht, maxIndex);
    }

}

void buildHeap(MaxHeap *ht)
{
    int startIndex = ht->size / 2 - 1;

    for(int i = startIndex; i >= 0; i--)
    {
        heapify(ht, i);
    }
}

//*************************************************************

void insert(MaxHeap *ht, int item)
{
    if(ht->size == ht->capacity){
        cout << "Overflowed!\n";
        return;
    }
    int currentIndex = ht->size;
    ht->tree[currentIndex] = item;
    ht->size++;

    while(currentIndex > 0)
    {
        int parentIndex = (currentIndex - 1) / 2;

        if (ht->tree[currentIndex] > ht->tree[parentIndex])
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

int remove(MaxHeap *ht)
{
    if(ht->size == 0)
    {
        cout << "Tree is empty!\n";
        return -404;
    }
    int removedNode = ht->tree[0];
    ht->tree[0] = ht->tree[ht->size - 1];
    ht->tree[ht->size - 1] = removedNode;
    ht->size--;

    heapify(ht, 0);

    return removedNode;
}

void display(MaxHeap *ht)
{
    if (ht->size < 1)
    {
        cout << "Tree is empty!\n";
        return;
    }
    for(int i = 0; i < ht->size; i++)
    {
        cout << ht->tree[i] << " ";
    }
    cout << "\n\n";
}

void sortHeap(MaxHeap *ht)
{
    int temp = ht->size;
    while(ht->size > 1)
    {
        remove(ht);
    }
    ht->size = temp;

    cout << "\nSorted : ";
    display(ht);

    ht->size = 0;
}

//*************************************************************

int main()
{
    MaxHeap *ht = new MaxHeap(20);
    insert(ht, 9);
    insert(ht, 4);
    insert(ht, 7);
    insert(ht, 1);
    insert(ht, 3);
    insert(ht, 20);

    display(ht);

    sortHeap(ht);
    display(ht);
//     srand(67);

//     for(int i = 0; i < 10; i++)
//         cout << rand() << " ";
}
