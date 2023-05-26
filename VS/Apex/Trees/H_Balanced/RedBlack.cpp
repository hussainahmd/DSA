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

Node* insert(Node *parent, Node *root, int item)
{
    if(root == NULL)
    {
        if(parent == NULL)
        {
            Node *node = new Node(item);
            node->color = 1;
            return node;
        }
        return new Node(item);
    }

    if (item < root->data)
        root->left = insert(root, root->left, item);

    else if (item > root->data)
        root->right = insert(root, root->right, item);

    else
        return root;
}