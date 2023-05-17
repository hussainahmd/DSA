#include <bits/stdc++.h>
using namespace std;

#define SIZE 10
int tree[SIZE], treeSize = 0;

void shift_up(int currentIndex)
{
    while (currentIndex > 0)
    {
        int parentIndex = (currentIndex - 1) / 2;

        if (tree[currentIndex] > tree[parentIndex])
        {
            // swap
            int temp = tree[currentIndex];
            tree[currentIndex] = tree[parentIndex];
            tree[parentIndex] = temp;

            currentIndex = parentIndex;
        }
        else
            break; // the tree is a heap now
    }

}

void shift_down()
{
    int currentIndex = 0;
    while (currentIndex < treeSize)
    {
        int leftChildIndex = 2 * currentIndex + 1;
        int rightChildIndex = 2 * currentIndex + 2;

        if (leftChildIndex >= treeSize)
            break; // The tree is a heap

        int maxIndex = leftChildIndex;
        if (rightChildIndex < treeSize)
        {
            if (tree[maxIndex] < tree[rightChildIndex])
            {
                maxIndex = rightChildIndex;
            }
        }

        // swap if current node is less than maximum
        if (tree[currentIndex] < tree[maxIndex])
        {
            int temp = tree[currentIndex];
            tree[currentIndex] = tree[maxIndex];
            tree[maxIndex] = temp;

            currentIndex = maxIndex;
        }
        else
            break; // The tree is a heap
    }
    
}

void insert(int item)
{
    if (treeSize == SIZE)
    {
        cout << "Overflowed!\n";
        return;
    }
    int currentIndex = treeSize;
    tree[currentIndex] = item;

    shift_up(currentIndex);

    treeSize++;
}

int remove()
{
    if (treeSize <= 0)
    {
        cout << "Tree is empty!\n";
        return -404;
    }
    int removedNode = tree[0];
    tree[0] = tree[treeSize - 1];
    treeSize--;

    shift_down();

    return removedNode;
}

int main()
{
    vector<int> heapTree;
    for (int i = 0; i < 5; i++)
    {
        heapTree.push_back(10 + i);
    }
    cout << heapTree.at(4);
}
