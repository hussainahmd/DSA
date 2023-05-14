#include <iostream>
using namespace std;

int GCD(int num1, int num2);
int LCM(int a, int b);
bool primeNum(int n);

int main(){

    int num1, num2, gcd;
    cout << "Enter two positive inetgers:\n";
    cin >> num1; cin >> num2;

    cout << "GCD is : " << GCD(num1, num2) << endl;

    cout << "LCM is : " << LCM(num1, num2) << endl;

    for(int i = 0; i < 101; i++){
        if(primeNum(i)){
            cout << i << " ";
        }
    }

    return 0;
}

int GCD(int num1, int num2){
    int gcd, temp;
    if(num1 < num2){
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
    if(num1 % num2 == 0){
            gcd = num2;
        }
        else{
            for(int i = num2; i > 0; i--){
                if(num1 % i == 0 && num2 % i == 0){
                    gcd = i;
                    break;
                }
            }
        }
    return gcd;
}

int LCM(int a, int b){

    int product = a * b;
    int gcd = GCD(a, b);

    return product / gcd;

}

bool primeNum(int n){

    if(n <= 1)
        return false;
    else{
        for(int i = 2; i < n; i++){
            if(n % i == 0)
                return false;
        }
        return true;
    }
}
