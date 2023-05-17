#include <iostream>
using namespace std;

void display(int **board, int n);
bool isSafe(int **board, int i, int j, int n);
int rec(int **board, int i, int n);
int N_Queens(int **board, int n);

int main()
{
    int n;
    cout << "\nEnter a value for N : ";
    cin >> n;
    cout << "\n";

    //initializing the board
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {

        arr[i] = new int[n];

        for (int j = 0; j < n; j++)
        {

            arr[i][j] = 0;
        }
    }

    int sol = N_Queens(arr, n);
    if (sol > 0)
        cout << "No. of Solutions for " << n << " Queens : " << sol << "\n\n";
    else
        cout << "No Solutions found for " << n << " Queens\n\n";

    //display(arr, n);
}

int N_Queens(int **board, int n)
{
    return rec(board, 0, n);
}

//go to the depth of the board while checking a solution for all rows and columns
int rec(int **board, int row, int n)
{
    //a solution has been found
    //print the board and return 1 as noOfSol
    if (row == n)
    {
        display(board, n);
        return 1;
    }
    else
    {
        int noOfSol = 0;
        //check for all the columns of the same row
        for (int col = 0; col < n; col++)
        {
            if (isSafe(board, row, col, n))
            {
                board[row][col] = 1; //place a queen
                noOfSol += rec(board, row + 1, n); //one complete possibility is checked
                board[row][col] = 0; //replace the cell with 0 to check further solutions
            }
        }
        return noOfSol;
    }
}

bool isSafe(int **board, int row, int col, int n)
{
    int col_Left = col;
    int col_Right = col;
    while (row >= 0)
    {
        //check the left upper diagonal cell
        if (col_Left >= 0 && board[row][col_Left] == 1)
            return false;

        //check the top cell
        if (board[row][col] == 1)
            return false;

        //check the right upper diagonal cell
        if (col_Right < n && board[row][col_Right] == 1)
            return false;

        row --; //go to previous row
        col_Left --;
        col_Right ++;
    }
    //return true if no threat
    return true;
}

void display(int **board, int n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)

            if (board[i][j] == 1)
                cout << "   Q";
            else
                cout << "   _";

        cout << "\n\n";
    }
    cout << "\n";
}