#include <bits/stdc++.h>
using namespace std;

//*******************************************
void menu();
void shift_up(int);
void shift_down(int);
void insert(int);
int removeRoot();
void inorder(int);
void sortHeap();
void display();
//*******************************************

#define SIZE 30
int tree[SIZE], treeSize = 0;

//*******************************************
int main()
{
    int choice;
    do
    {
        menu();
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            int x;
            cout << "Enter a number : ";
            cin >> x;
            insert(x);
            cout << "Item inserted : " << x << "\n";
            break;

        case 2:
        {
            int y = removeRoot();
            if (y != -404)
                cout << "Item removed : " << y << "\n";
        }
        break;

        case 3:
            sortHeap();
            cout << "\nSorted tree : ";
            display();
            treeSize = 0;
            cout << "\n";
            break;
        
        case 4:
            cout << "\nInorder : ";
            inorder(0);
            cout << "\n\n";
            break;

        case 5:
            cout << "\nTree : ";
            display();
            cout << "\n";
            break;

        default:
            cout << "Thank You!\n";
        }
        cout << endl;
    } while (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5);
}

//*******************************************

void shift_up(int currentIndex)
{
    // while not the top most node (root) of the tree
    while (currentIndex > 0)
    {
        int parentIndex = (currentIndex - 1) / 2;

        if (tree[currentIndex] > tree[parentIndex])
        {
            // swap
            int temp = tree[currentIndex];
            tree[currentIndex] = tree[parentIndex];
            tree[parentIndex] = temp;

            // shift current to the parent and check again
            currentIndex = parentIndex;
        }
        else
            break; // the tree is a heap now
    }
}

void shift_down(int currentIndex) //heapify
{
    //int currentIndex = 0;
    while (currentIndex < treeSize)
    {
        int leftChildIndex = 2 * currentIndex + 1;
        int rightChildIndex = 2 * currentIndex + 2;

        int maxIndex = currentIndex;
        
        if (leftChildIndex < treeSize && tree[leftChildIndex] > tree[maxIndex])
        {
            maxIndex = leftChildIndex; 
        }

        if (rightChildIndex < treeSize && tree[rightChildIndex] > tree[maxIndex])
        {
            maxIndex = rightChildIndex; 
        }

        if(maxIndex != currentIndex)
        {
            int temp = tree[currentIndex];
            tree[currentIndex] = tree[maxIndex];
            tree[maxIndex] = temp;

            currentIndex = maxIndex;
        }
        else
            break;
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

int removeRoot() // remove root of the tree
{
    if (treeSize <= 0)
    {
        cout << "Tree is empty!\n";
        return -404;
    }
    int removedNode = tree[0];
    tree[0] = tree[treeSize - 1];
    tree[treeSize - 1] = removedNode;
    treeSize--;

    shift_down(0);

    return removedNode;
}

void sortHeap()
{
    int size = treeSize;
    while (treeSize > 1)
    {
        removeRoot();
    }
    treeSize = size;
}

void display()
{
    if (treeSize < 1)
    {
        cout << "Tree is empty!\n";
        return;
    }
    for(int i = 0; i < treeSize; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
}

void inorder(int current)
{
    if (treeSize < 1)
    {
        cout << "Tree is empty!\n";
        return;
    }
    int left = 2 * current + 1;
    int right = 2 * current + 2;

    // if the current node has left child, inorder left
    if (left < treeSize)
    {
        inorder(left);
    }
    // if left node does not exist then right also not exists
    // so print the value of node and return
    else
    {
        cout << tree[current] << " ";
        return;
    }

    // print the value of current node
    cout << tree[current] << " ";

    // if the current has right child, inorder right else return
    if (right < treeSize)
    {
        inorder(right);
    }
}

void menu()
{
    cout << "---------MaxHeap---------\n"
         << "1. Insert a value\n"
         << "2. Remove root\n"
         << "3. Sort Max Heap\n"
         << "4. Display inorder\n"
         << "5. Display tree\n"
         << ".. Any other key to Quit\n"
         << "Your option ? : ";
}
