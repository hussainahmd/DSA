#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    bool color = 0;
    Node *parent = NULL;
    Node *left = NULL;
    Node *right = NULL;

    Node(int item)
    {
        data = item;
    }
};

Node* insert(Node *root, int item)
{
    if(root == NULL)
        return new Node(item);

    if (item < root->data)
        root->left = insert(root->left, item);

    else if (item > root->data)
        root->right = insert(root->right, item);

    else
        return root;
}