#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";

    v.pop_back();
    cout << v[v.size()-1];
    
    return
}
