#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int size)
{
    for (int currIndex = 1; currIndex < size; currIndex++)
    {
        int prevIndex = currIndex - 1;

        while (prevIndex >= 0 && arr[currIndex] < arr[prevIndex])
        {
            arr[prevIndex + 1] = arr[prevIndex];
            prevIndex--;
        }

        arr[prevIndex + 1] = arr[currIndex];
    }
}

void selectionSort(int arr[], int size)
{
    for (int currIndex = 0; currIndex < size - 1; currIndex++)
    {
        int minIndex = currIndex;
        int temp = arr[currIndex];

        // find the min value in the array
        for(int nextIndex = currIndex + 1; nextIndex < size; nextIndex++)
        {
            if(arr[nextIndex] < arr[currIndex])
            {
                minIndex = nextIndex;
                temp = arr[nextIndex];
            }
        }
        // swap the minValueIndex with currentIndex
        arr[minIndex] = arr[currIndex];
        arr[currIndex] = temp;
    }
}

void display(int arr[])
{   
    int size = sizeof(arr) / sizeof(int);
    cout << "Array : ";
    for (int currIndex = 0; currIndex < size; currIndex++)
    {
        cout << arr[currIndex] << " ";
    }
    cout << "\n";
}