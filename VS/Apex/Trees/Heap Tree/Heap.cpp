#include <bits/stdc++.h>
using namespace std;

struct HeapTree
{
    int tree[20];
    int size = 0;
};

//*******************************************

void heapify(int tree[], int currentIndex, int treeSize)
{
    int leftChildIndex = 2 * currentIndex + 1;
    int rightChildIndex = 2 * currentIndex + 2;

    int maxIndex = currentIndex;

    if(leftChildIndex < treeSize && tree[leftChildIndex] > tree[maxIndex])
    {
        maxIndex = leftChildIndex;   
    }

    if(rightChildIndex < treeSize && tree[rightChildIndex] > tree[maxIndex])
    {
        maxIndex = rightChildIndex;   
    }

    if(maxIndex != currentIndex)
    {
        swap(tree[currentIndex], tree[maxIndex]);
        heapify(tree, maxIndex, treeSize);
    }

}

void buildHeap(int tree[], int treeSize)
{
    int startIndex = treeSize / 2 - 1;

    for(int currentIndex = startIndex; currentIndex >= 0; currentIndex--)
    {
        heapify(tree, currentIndex, treeSize);
    }
}