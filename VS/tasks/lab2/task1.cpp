#include<iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

void task1();
void task2();
void task3();
void task4();

void menu(){
    cout << "----------MENU----------\n"
        << "1. 2nd max element and 3rd min element from the array\n"
        << "2. Find the transpose of a matrix\n"
        << "3. Sum of all even no.'s from an array\n"
        << "4. Multiplication of 2-dimensional array\n"
        << "   Enter your choice : ";
}

int main(){

    bool found = true;
    while (found){
        menu();
        int choice;
        cin >> choice;

        switch(choice){

            case 1: task1();
                    break;

            case 2: task2();
                    break;

            case 3: task3();
                    break;

            case 4: task4();
                    break;

            default: found = false;
                    break;
        }


        if(found == false)
            break;
    }


    return 0;
}

void task1(){
    int arr[]{10,2,34,65,12,7,3,1,9,76,33,52,78,26,49,0,32,71,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int loc1, loc2, loc3, index, index2 = 0;
    int maxV = arr[0]; int minV = arr[0];
    int max2 = arr[0];
    int min2 = arr[0];
    int min3 = arr[0];

    for(int i = 0; i < n; i++){
        if(arr[i] > maxV){
            maxV = arr[i];
            loc1 = i;
        }
        if(arr[i] < minV){
            minV = arr[i];
            loc2 = i;
        }
    }
    for(int i = 0; i < n; i++){
        if(arr[i] != arr[loc1] && arr[i] > max2){
            max2 = arr[i];
            index = i;
        }
        if(arr[i] != arr[loc2] && arr[i] < min2){
            min2 = arr[i];
            loc3 = i;
        }
    }

    for(int  i = 0; i < n; i++){
        if(arr[i] != arr[loc3] && arr[i] != arr[loc2] && arr[i] < min3){
            min3 = arr[i];
            index2 = i;
        }
    }

    cout << "\n2nd max value is : " << max2 << " at index " << index << endl
    << "3rd min value is : " << min3 << " at index " << index2 << endl << endl;
}

void task2(){
    int arr1[3][3]{{1,2,3},
                  {4,5,6},
                  {7,8,9}};
    int arr2[3][3];

    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){

            arr2[j][i] = arr1[i][j];
        }
    }
    cout << "\nOriginal array : \n";
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){

            cout << arr1[i][j] << " ";
            if (j == 3 - 1)
                cout << endl;
        }
    }
    cout << "Transpose array : \n";
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){

            cout << arr2[i][j] << " ";
            if (j == 3 - 1)
                cout << endl;
        }
    }
    cout << endl << endl;

}

void task3(){
    int arr[]{23,5,2,6,8,4,2,1,8,6,43,1,4,6,8,45,6,3,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum;
    for(int  i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            sum += arr[i];
        }
    }
    cout << "\nSum of even numbers : " << sum << endl << endl;
}

void task4(){
    int arr1[3][3]{{1,2,3},
                  {4,5,6},
                  {7,8,9}};

    int arr2[3][3]{{11,3,6},
                  {2,1,0},
                  {7,1,4}};

    int arr3[3][3];

    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            for(int k = 0; k < 3; k++){

                arr3[i][j] = arr1[i][k] * arr2[k][j];
            }
        }
    }
    cout << "\nFirst array :\n";
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            cout << arr1[i][j] << " ";
        }
    cout << endl;
    }

    cout << "\nSecond array :\n";
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            cout << arr2[i][j] << " ";
        }
    cout << endl;
    }
    cout << "\nResult array :\n";
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            cout << arr3[i][j] << " ";
        }
    cout << endl << endl;
    }
}


