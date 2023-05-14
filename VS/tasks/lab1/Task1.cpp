#include <iostream>
#include<string>
#include <algorithm>
using namespace std;

int factorial(int a);
void fibonacci(int a, int b);
int counter(int n);
int countDigit(int n);
void numReverse(int n);
void menu();

int main(){

    int choice;
    do{
        menu();
        cin >> choice; cout << endl;

        switch(choice){
            case 1:
                int num;
                cout << "Enter a positive number : ";
                cin >> num;
                cout << "The factorial of " << num << " is : " << factorial(num) << endl;
                break;

            case 2:
                cout << "The fibonacci sequence of 0 and 1 of length 10 is :" << endl;
                fibonacci(0 , 1); cout << endl;
                break;

            case 3:
                 int x;
                cout << "Enter an integer : ";
                cin >> x;
                cout << "The no. of digits int the given integer : " << countDigit(x) << endl;
                break;

            case 4:
                int y;
                cout << "Enter a number : ";
                cin >> y;
                cout << "The reverse of the given number is : ";
                numReverse(y); cout << endl;
                break;

            default:
                cout << "Invalid option";
        }
        cout << endl;
    }while(choice != 1 || choice != 2 || choice != 3 || choice != 4);


    return 0;
}

int factorial(int num) {
    if(num > 1)
        return num * factorial(num - 1);
    else
        return 1;
}

void fibonacci(int a, int b){
    int temp = 0;
    for(int i = 0; i < 10; i++){
        cout << a + b << " ";
        temp = a + b;
        a = b;
        b = temp;
    }
}

int counter(int n){
    string s = to_string(n);
    return s.length();
}
int countDigit(int n)
{
    if (n/10 == 0)
        return 1;
    return 1 + countDigit(n / 10);
}

void numReverse(int n){
    string s = to_string(n);
    reverse(s.begin(), s.end());
    cout << s;
}

void menu(){
    cout << "---------Menu---------\n"
         << "1. Find the factorial of a number\n"
         << "2. Fibonacci sequence\n"
         << "3. Count the no. of digits in an integer\n"
         << "4. Reverse a number\n"
         << "Enter your choice : ";
}
