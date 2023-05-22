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

    int current_height = max(left_subtree->height, right_subtree->height) + 1;
    int height_diff = abs(left_subtree->height - right_subtree->height);

    if(height_diff <= 1 && left_subtree->balanced && right_subtree->balanced);
        return new answer(current_height, true);

    return new answer(current_height, false);
}

void insert(Node *&root, int item)
{
    if (root == NULL)
    {
        root = new Node(item);
        return;
    }

    if (item < root->data)
    {
        insert(root->left, item);
        //bool left_Balanced = is_Balanced(root->left);
    }

    if (item > root->data)
    {
        insert(root->right, item);
    }
        
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(20);
    root->right = new Node(70);

    answer *ans = is_Balanced(root);
    if(ans->balanced)
        cout << "The tree is height-balanced.\n";
    else
        cout << "The tree is not height-balanced.\n";

    cout << "The height of the tree is: " << ans->height << "\n";
}