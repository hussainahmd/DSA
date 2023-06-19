#include <bits/stdc++.h>/////
#include<vector>
using namespace std;

int main()
{
    int x = 11/2 - 1;

    cout << x;
    
    return 0;
}
void binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = (l + r) / 2;
        if (arr[mid] == x) {
            cout << mid;
        }
        if (arr[mid] > x) {
            binarySearch(arr, l, mid - 1, x);
        }
        binarySearch(arr, mid + 1, r, x);
    }
    cout << -1;
}
