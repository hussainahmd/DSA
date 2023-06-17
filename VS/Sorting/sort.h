#include <bits/stdc++.h> /////
using namespace std;

void merge(int arr[], int leftIndex, int middleIndex, int rightIndex)
{
    // Calculate the sizes of the left and right arrays
    int n1 = middleIndex - leftIndex + 1;
    int n2 = rightIndex - middleIndex;

    // Create left and right arrays
    int leftArray[n1], rightArray[n2];

    // Copy the elements of the left array to the leftArray
    for (int i = 0; i < n1; i++)
        leftArray[i] = arr[leftIndex + i];

    // Copy the elements of the right array to the rightArray
    for (int j = 0; j < n2; j++)
        rightArray[j] = arr[middleIndex + 1 + j];

    // Merge the left and right arrays into the original array
    int i = 0, j = 0, k = leftIndex;

    // Copy the smaller element from leftArray and rightArray to the original array
    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            arr[k] = leftArray[i];
            i++;
        }
        else
        {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray to the original array
    while (i < n1)
    {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray to the original array
    while (j < n2)
    {
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

// Merge Sort function to sort an array using Merge Sort
void mergeSort(int arr[], int startIndex, int endIndex)
{
    // If the sub-array has more than one element, divide it into two halves and sort them recursively
    if (startIndex < endIndex)
    {
        // Calculate the middle index of the sub-array
        int middleIndex = (startIndex + endIndex) / 2;

        // Sort the left half of the sub-array using mergeSort
        mergeSort(arr, startIndex, middleIndex);

        // Sort the right half of the sub-array using mergeSort
        mergeSort(arr, middleIndex + 1, endIndex);

        // Merge the sorted left and right halves of the sub-array using merge
        merge(arr, startIndex, middleIndex, endIndex);
    }
}

//*****************************************************************************

// Partition function to rearrange the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // Select the first element as pivot
    int left = low + 1;   // Start from the next element
    int right = high;

    while (true)
    {
        // Move the left pointer to the right until a larger element is found
        while (left <= right && arr[left] <= pivot)
        {
            left++;
        }

        // Move the right pointer to the left until a smaller element is found
        while (right >= left && arr[right] >= pivot)
        {
            right--;
        }

        // If the pointers cross, break the loop
        if (left > right)
        {
            break;
        }

        // Swap arr[i] and arr[j] to maintain the partitioning
        swap(arr[left], arr[right]);
    }

    // Move the pivot element to its correct position
    swap(arr[low], arr[right]);

    // Return the pivot index
    return right;
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

//*****************************************************************************

void insertionSort(int arr[], int size)
{
    // Iterate through the array starting from the second element
    for (int currIndex = 1; currIndex < size; currIndex++)
    {
        // Save the current element to be inserted
        int temp = arr[currIndex];

        // Find the correct position to insert the current element
        int prevIndex = currIndex - 1;

        while (prevIndex >= 0 && temp < arr[prevIndex])
        {
            // Shift the elements to the right to make room for the current element
            arr[prevIndex + 1] = arr[prevIndex];
            prevIndex--;
        }

        // Insert the current element at the correct position
        arr[prevIndex + 1] = temp;
    }
}

//*****************************************************************************

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

//*****************************************************************************

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
