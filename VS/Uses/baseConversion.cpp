#include "C:\Users\Hussain\Desktop\DSA\VS\Classes\Stack\Stack.h"
#include <iostream>
#include <cmath>

using namespace std;

void decToBin();
void binToDec();
void decToHex();
void hexToDec();
void menu();

int main(){

    try{
        bool found = true;
        while (found){
            menu();
            int choice;
            cin >> choice;

            switch(choice){

                case 1: decToBin();
                        break;

                case 2: binToDec();
                        break;

                case 3: decToHex();
                        break;

                case 4: hexToDec();
                        break;

                default: found = false;
                        break;
            }
            cout << endl;

            if(found == false)
                break;
        }
    }catch(exception &e){
        cerr << e.what() << endl;
    }
    return 0;
}

void hexToDec(){

    cout << endl;
    string hex;
    cout << "Enter a Hexa value : "; cin >> hex;
    int res = 0;

    Stack<char> stack(hex.length());

    for(int i = 0; i < hex.length(); i ++){
            stack.push(hex[i]);
    }

    for(int i = 0; i < hex.length(); i++){
        char c = stack.peek();
        if(c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E' || c == 'F')
            res += pow(16, i) * (stack.pop() - 55);
        else
            res += pow(16, i) * (stack.pop() - 48);
    }
    cout << "Decimal : " << res << endl;
}

void decToHex(){

    cout << endl;
    int value;
    cout << "Enter an integer (>0) : "; cin >> value;
    if(value <= 0){
        do{
            cout << "Integer must be greater than 0! Try again : "; cin >> value;
        }while(value <= 0);
    }
    int x = value;

    Stack<char> obj(50);

    int count = 0;
    while(value > 0){
        int a = value % 16;
        if(a >= 10 && a <= 15){
            switch (a){
                case 10:
                    obj.push('A');
                    break;
                case 11:
                    obj.push('B');
                    break;
                case 12:
                    obj.push('C');
                    break;
                case 13:
                    obj.push('D');
                    break;
                case 14:
                    obj.push('E');
                    break;
                case 15:
                    obj.push('F');
                    break;
            }
        }
        else{
            obj.push(a + 48);
        }
        value = value / 16;
        count++;
    }

    cout << x << " to Hexadecimal : ";
    for(int i = 0; i < count; i ++){
        cout << obj.pop() << " ";
    }
    cout << endl;
}

void decToBin(){

    cout << endl;
    int value;
    cout << "Enter an integer (>0) : "; cin >> value;
    if(value <= 0){
        do{
            cout << "Integer must be greater than 0! Try again : "; cin >> value;
        }while(value <= 0);
    }
    int x = value;

    Stack<int> obj(50);
    
    int count = 0;
    while(value > 0){
        obj.push(value % 2);
        value = value / 2;
        count++;
    }
    cout << x << " to Binary : ";
    for(int i = 0; i < count; i ++){
        cout << obj.pop() << " ";
    }
    //obj.display();
    cout << endl;
}

void binToDec(){

    cout << endl;
    int bin;
    cout << "Enter a binary value : "; cin >> bin;
    int dup = bin;
    int count = 0;

    do{
        dup /= 10;
        count ++;
    }while(dup > 0);

    Stack<int> stack(count);

    int i = count;
        while(bin > 0){
            int x = bin % 10;
            stack.push(x);
            bin /= 10;
            i --;
    }

    int res = 0;
    for(int i = 0; i < count; i++){
        res += pow(2, stack.top) * stack.pop();
    }
    cout << "Decimal : " << res << endl;

}

void menu(){
    cout << "----------MENU----------\n"
        << "1. Decimal to Binary\n"
        << "2. Binary to Decimal\n"
        << "3. Decimal to Hexa\n"
        << "4. Hexa to Decimal\n"
        << "?. Any other key to terminate\n"
        << "   Enter your choice : ";
}