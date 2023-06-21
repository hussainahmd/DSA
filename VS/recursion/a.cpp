#include <iostream>
using namespace std;

string reverseString(string);
bool isPalindrome(string);
string decimalToBinary(int, string);
int summation(int);
int fibonacci(int);

int main()
{
    string s = "123321";
    string rs = reverseString(s);

    if (isPalindrome(s))
        cout << "yes : " << rs << "\n";

    string res = decimalToBinary(233, "");
    cout << res << "\n";

    cout << summation(3);
}

int fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

string reverseString(string s)
{
    if (s == "")
        return "";

    return (reverseString(s.substr(1))) + s[0];
}

bool isPalindrome(string s)
{
    if (s.length() == 0 || s.length() == 1)
        return true;

    if (s[0] == s[s.length() - 1])
        return isPalindrome(s.substr(1, s.length() - 2));

    return false;
}

string decimalToBinary(int decimal, string result)
{
    if (decimal == 0)
        return result;

    result = to_string(decimal % 2) + result;

    return (decimalToBinary(decimal / 2, result));
}

int summation(int value)
{
    if (value <= 1)
        return value;

    return summation(value - 1) + value;
}