#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;

    Node(int item)
    {
        data = item;
    }
};

bool is_Balanced(Node *root, int& height)
{
    if(!root){
        height = 0;
        return true;
    }

    int left_Height, right_Height;
    if(!is_Balanced(root->left, left_Height))
        return false;

    if(!is_Balanced(root->right, right_Height))
        return false;
    
    int current_height = max(left_Height, right_Height) + 1;
    
}

int main()
{
}