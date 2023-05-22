#include <bits/stdc++.h>
#include "C:\Users\Hussain\Desktop\DSA\VS\Apex\Trees\funcs_BT_BST.h"
using namespace std;

//*******************************************************************
struct answer
{
    int height;
    bool balanced;

    answer(int a, bool b){
        height = a;
        balanced = b;
    }
};

answer* is_Balanced(Node *root)
{
    if(root == NULL)
        return new answer(0, true);

    answer *left_subtree = is_Balanced(root->left);
    answer *right_subtree = is_Balanced(root->right);

    int left_height = left_subtree->height;
    int right_height = right_subtree->height;

    int current_height = max(left_height, right_height) + 1;
    int height_diff = abs(left_height - right_height);

    if(height_diff <= 1 && left_subtree->balanced && right_subtree->balanced)
        return new answer(current_height, true);
        
    return new answer(current_height, false);
}
//*******************************************************************

void insert(Node *&root, int item)
{
    if (root = NULL)
    {
        root = new Node(item);
        return;
    }

    if (item < root->data)
        insert(root->left, item);

    if (item > root->data)
        insert(root->right, item);
}

//*******************************************************************

int main()
{
    Node *root = new Node(50);
    root->left = new Node(20);
    root->right = new Node(70);
    root->left->left = new Node(10);
    root->left->right = new Node(15);
    // root->right->right = new Node(90);
    // root->right->left = new Node(80);
    root->left->left->left = new Node(5);

    answer *ans = is_Balanced(root);
    if(ans->balanced)
        cout << "The tree is height-balanced.\n";
    else
        cout << "The tree is not height-balanced.\n";

    cout << "The height of the tree is: " << ans->height << "\n******************************\n";

    print(root);
}