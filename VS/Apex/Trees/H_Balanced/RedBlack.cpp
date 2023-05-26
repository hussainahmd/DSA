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

Node *sibling(Node *root)
{
    if(root->data > root->parent->data)
    {
        return root->parent->left;
    }
    else
        return root->parent->right;
}

Node* insertUtil(Node *root, int item)
{
    if(root == NULL)
    {
        return new Node(item);
    }

    if (item < root->data)
    {
        root->left = insertUtil(root->left, item);
        root->left->parent = root;
    }

    else if (item > root->data)
    {
        root->right = insertUtil(root->right, item);
        root->right->parent = root;
    }

    else
        return root;

    if(root->color == 1)
        return root;

    if(root->color == 0)
    {
        if(sibling(root)->color == 1)
        {

        }
        else // sibling(root)->color == 0
        {

        }
    }
}

void insert(Node *&root, int item)
{
    if(root == NULL){
        root = new Node(item);
        root->color = 1;
    }
    else
        root = insertUtil(root, item);
}

int main()
{
    Node *root = NULL;
    insert(root, 50);
}