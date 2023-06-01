#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    bool color = 0; // 0 = red, 1 = black
    Node *parent = NULL;
    Node *left = NULL;
    Node *right = NULL;

    Node(int item)
    {
        data = item;
    }
};

//******************************************************************//

Node *getSibling(Node *root)
{
    if(root->data > root->parent->data)
    {
        return root->parent->left;
    }
    else
        return root->parent->right;
}

void recolor(Node *&root)
{
    if(root->color == 1)
        root->color = 0;
    else
        root->color = 1;
}

//******************************************************************//

Node *rotate_right(Node *root)
{
    Node *new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;

    return new_root;
}

Node *rotate_left(Node *root)
{
    Node *new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;

    return new_root;
}

//******************************************************************//

void printUtil(Node *&root, int space, int count)
{ // using reverse inorder
    if (!root)
        return;

    // Increase distance between levels
    space += count;

    printUtil(root->right, space, count);

    cout << endl;
    for (int i = count; i < space; i++)
        cout << " ";
    cout << root->data << "\n";

    printUtil(root->left, space, count);
}

void print(Node *&root)
{
    if(!root){
        cout << "Tree is empty!\n";
        return;
    }
    printUtil(root, 0, 10);
}

//******************************************************************//
