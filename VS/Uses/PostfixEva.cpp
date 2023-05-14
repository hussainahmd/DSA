#include "C:\Users\Hussain\Desktop\DSA\VS\Classes\Stack\Stack.h"
#include<iostream>
#include<cmath>
using namespace std;

bool isDigit(char);
bool isOperator(char);

int main(){
    string postfix;
    cout << "\nEnter a Postfix expression : "; getline(cin, postfix);
    int res = 0;

    Stack<int> stack(postfix.length());

    for(int i=0; i<postfix.length(); i++){

        char ch = postfix[i];
        if(ch == ' ')
            continue;

        else if(isDigit(ch)){

            int num = 0;
            while(isDigit(ch)){
                num = num * 10 + (ch - 48);
                i++;
                ch = postfix[i];
            }
            i--;
            stack.push(num);
        }

        else{
            if(stack.top < 1)
                throw runtime_error("Error! Invalid postfix expression");

            else{
                switch(ch){
                    case '+':
                        stack.push(stack.pop() + stack.pop());
                        break;
                    case '*':
                        stack.push(stack.pop() * stack.pop());
                        break;
                    case '/':
                    case '-':
                    case '%':
                    case '^':
                        int top1 = stack.pop();
                        int top2 = stack.pop();
                        if(ch == '/')
                            stack.push(top2 / top1);
                        else if(ch == '%')
                            stack.push(top2 % top1);
                        else if(ch == '-')
                            stack.push(top2 - top1);
                        else
                            stack.push(pow(top2, top1));
                        break;
                }
            }
        }
    }
    if(stack.top > 0)
        throw runtime_error("Error! Invalid postfix expression");
    else{
        cout << "Result : " << stack.peek() << "\n\n";
    }
    return 0;
}

bool isDigit(char ch){
    if(ch >= '0' && ch <= '9')
        return true;
    return false;
}

bool isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^')
        return true;
    return false;
}

