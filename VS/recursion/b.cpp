#include <iostream>//
using namespace std;

int binarySearch(int *, int, int, int);

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    
    cout << binarySearch(arr, 0, 12, 11);
}

int binarySearch(int *arr, int left, int right, int key)
{
    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }

    if (key < arr[mid])
    {
        return binarySearch(arr, left, mid - 1, key);
    }

    return binarySearch(arr, mid + 1, right, key);
}
