/*
Given a number, find its two factors whose sum is the minimum.
e.g)
    num = 30
    pair1 = 10 * 3 -> 13
    pair2 = 30 * 1 -> 31
    pair3 = 15 * 2 -> 17
    pair4 = 5 * 6  -> 11

*/


#include <iostream>
using namespace std;

bool is_prime(int n);
void func(int num);

int  main(){
    int num;
    cin >> num;
    func(num);
}

void func(int num){
    int arr[2] = {0,0};
    int a = 0, b = 0;

    if(is_prime(num)){
        arr[0] = 1;
        arr[1] = num;
        cout << "\n " << arr[0] << " " << arr[1];
        return;
    }
    
    int mid = num / 2; 
    arr[1] = 99999;
    for(int i = 2; i < mid; i++){
        if(num % i == 0){
            a = i;
            b = num / i;
        }
        else
            continue;

        if(a + b < arr[0] + arr[1]){
            arr[0] = a;
            arr[1] = b;
        }
    }
    cout << "\n " << arr[0] << " " << arr[1];
}

bool is_prime(int n){
    if(n == 1 || n == 2 || n == 3){
        return true;
    }
    bool flag = true;
    for(int i = 2; i < n; i++){
        if(n % i == 0){
            flag = false;
        }
    }
    return flag;
}