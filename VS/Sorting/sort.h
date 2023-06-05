#include <bits/stdc++.h>
using namespace std;

// Partition function to rearrange the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // Select the first element as pivot
    int i = low + 1;      // Start from the next element
    int j = high;

    while (true)
    {
        // Move the left pointer to the right until a larger element is found
        while (i <= j && arr[i] <= pivot)
        {
            i++;
        }

        // Move the right pointer to the left until a smaller element is found
        while (j >= i && arr[j] >= pivot)
        {
            j--;
        }

        // If the pointers cross, break the loop
        if (i > j)
        {
            break;
        }

        // Swap arr[i] and arr[j] to maintain the partitioning
        swap(arr[i], arr[j]);
    }

    // Move the pivot element to its correct position
    swap(arr[low], arr[j]);

    // Return the pivot index
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) 
    {
        // Partition the array
        int pivotIndex = partition(arr, low, high);

        // Recursively sort the two partitions
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void insertionSort(int arr[], int size)
{
    for (int currIndex = 1; currIndex < size; currIndex++)
    {
        int temp = arr[currIndex];
        int prevIndex = currIndex - 1;

        while (prevIndex >= 0 && temp < arr[prevIndex])
        {
            arr[prevIndex + 1] = arr[prevIndex];
            prevIndex--;
        }

        arr[prevIndex + 1] = temp;
    }
}

void selectionSort(int arr[], int size)
{
    for (int currIndex = 0; currIndex < size - 1; currIndex++)
    {
        int minIndex = currIndex;
        int temp = arr[currIndex];

        // find the min value in the array
        for (int nextIndex = currIndex + 1; nextIndex < size; nextIndex++)
        {
            if (arr[nextIndex] < temp) //
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

void display(int arr[], int size)
{
    // int size = sizeof(arr) / sizeof(int);
    cout << "\nArray : ";
    for (int currIndex = 0; currIndex < size; currIndex++)
    {
        cout << arr[currIndex] << " ";
    }
    cout << "\n";
}