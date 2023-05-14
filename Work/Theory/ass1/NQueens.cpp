#include<iostream>
using namespace std;

void display(int **board, int n);
bool isSafe(int **board, int i, int j, int n);
int rec(int **board, int i, int n);
int N_Queens(int **board, int n);

int main(){

    int n;
    cout << "\nEnter a value for N : ";
    cin >> n; cout << "\n";

    int** arr = new int*[n];
    for(int i = 0; i < n ; i++){
        
        arr[i] = new int[n];

        for (int j = 0; j < n; j++){

            arr[i][j] = 0;
        }
    }

    int sol = N_Queens(arr, n);
    if(sol > 0)
        cout << "No. of Solutions for " << n << " Queens : " << sol << "\n";
    else
        cout << "No Solutions found for " << n << " Queens\n";
}

int N_Queens(int **board, int n){

    return rec(board, 0, n);
    
}

int rec(int **board, int i, int n){

    if(i == n){
        display(board, n);
        return 1;
    }
    else{
        int noOfSol = 0;
        for(int j = 0; j < n; j++){

            if(isSafe(board, i, j, n)){
                board[i][j] = 1;
                noOfSol += rec(board, i + 1, n);
                board[i][j] = 0;
            }
        }
        return noOfSol;
    }
}

bool isSafe(int **board, int i, int j, int n){
    
    int jLeft = j;
    int jRight = j;
    while(i >= 0){
        if(jLeft >= 0 && board[i][jLeft] == 1)
            return false;
        if(board[i][j] == 1)
            return false;
        if(jRight < n && board[i][jRight] == 1)
            return false;
        
        i -= 1;
        jLeft -= 1;
        jRight += 1;
    }
    return true;
}

void display(int **board, int n){

    for(int i = 0; i < n ; i++){

        for (int j = 0; j < n; j++)

            if(board[i][j] == 1)
                cout << "   Q";
            else
                cout << "   _";
        
        cout << "\n\n";
    }
    cout << "\n";
}