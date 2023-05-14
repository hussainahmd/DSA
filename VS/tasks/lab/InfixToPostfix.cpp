#include "C:\Users\Hussain\Desktop\DSA\VS\Classes\Stack\Stack.h"
#include <iostream>
using namespace std;

bool isValid(string);
bool isOperand(char);
bool isOperator(char);
bool isOpBracket(char);
bool isCloBracket(char);
int precedence(char);
bool priority(char, char);
void infixToPostfix();

//Main method
int main(){
    try{
        infixToPostfix();

    }catch(exception &e){
        cerr << e.what() << "\n\n";
    }
}

void infixToPostfix(){
    
    string s;
    cout << "\nEnter an Infix expression : "; getline(cin, s);
    string postfix;

    if(!isValid(s))
        throw runtime_error("Error! Invalid expression");

    Stack<char> stack(s.length());

    for(int i = 0; i < s.length(); i ++){
        
        char ch = s[i];
        
        if(ch == ' ') 
            continue;
        
        else if(isOpBracket(ch))
            stack.push(ch);

        else if(isOperand(ch))
            postfix += ch;
        
        else if(isOperator(ch)){
            if(stack.isEmpty())
                stack.push(ch);
            else{
                while(!stack.isEmpty() && priority(ch, stack.peek()))
                    postfix += stack.pop();
                stack.push(ch);
            }
        }
        else if(isCloBracket(ch)){

            switch (ch){
            case ')':
                while(!stack.isEmpty() && stack.peek() != '(')
                    postfix += stack.pop();
                break;
            case '}':
                while(!stack.isEmpty() && stack.peek() != '{')
                    postfix += stack.pop();
                break;
            case ']':
                while(!stack.isEmpty() && stack.peek() != '[')
                    postfix += stack.pop();
                break;
            }
            stack.pop();//rem opBracket from stack
        }
        
    }
    while(!stack.isEmpty())
        postfix += stack.pop();

    cout << "\nPostfix expression : " << postfix << "\n\n";
}

bool isValid(string s){
    Stack<char> stack(s.length());

    for(int i = 0; i < s.length(); i ++){
        
        char ch = s[i];

        if(isOpBracket(ch))
            stack.push(ch);
        
        else if(isCloBracket(ch)){
            if(stack.isEmpty())
                return false;

            else{
                switch (ch){
                case ')':
                    if(stack.pop() != '(')
                        return false;
                    break;
                case '}':
                    if(stack.pop() != '{')
                        return false;
                    break;
                case ']':
                    if(stack.pop() != '[')
                        return false;
                    break;
                }

            }
        }
        else if(isOperand(ch) || isOperator(ch))
            continue;

        else
            return false;
    }
    if(!stack.isEmpty())
        return false;
    
    return true;
}

bool isOperand(char ch){
    if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9')
        return true;
    return false;
}

bool isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^')
        return true;
    return false;
}

bool isOpBracket(char ch){
    if(ch == '(' || ch == '{' || ch == '[')
        return true;
    return false;
}

bool isCloBracket(char ch){
    if(ch == ')' || ch == '}' || ch == ']')
        return true;
    return false;
}

int precedence(char ch){
    switch(ch){

        case '^':
            return 3;
            break;

        case '*':
        case '/':
        case '%':
            return 2;
            break;

        case '+':
        case '-':
            return 1;
            break;
    }
}

bool priority(char ch, char stackTop){
    if(isOpBracket(stackTop) || precedence(ch) > precedence(stackTop))
        return false;//push
    if(precedence(ch) <= precedence(stackTop))
        return true;//check for next ch on stackTop
}