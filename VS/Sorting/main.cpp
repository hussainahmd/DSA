#include"sort.h"

int main()
{
    int size = 10;
    int arr[] = {6, 3, 9, 12, 67, 1, 8, 43, 22, 10};

    display(arr, size);

    //selectionSort(arr, size);
    mergeSort(arr, 0, size - 1);
    display(arr, size);
}