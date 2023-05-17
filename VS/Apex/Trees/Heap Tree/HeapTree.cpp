#include <bits/stdc++.h>
using namespace std;

struct MaxHeap{
    int *arr;
    int arrSize
}

// void insert(int *tree, int item)
// {
//     tree.push_back(item);
//     int currentIndex = tree.size() - 1;
// }

int main()
{
    vector<int> heapTree;
    for(int i = 0; i < 5; i++){
        heapTree.push_back(10 + i);
    }
    cout << heapTree.at(4);
}

