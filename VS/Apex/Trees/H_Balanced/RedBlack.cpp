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
        Node *node = new Node(item);
        if(parent == NULL)
        {
            node->color = 1;
            return node;
        }
        node->parent = parent;
        return node;
    }

    if (item < root->data)
        root->left = insert(root, root->left, item);

    else if (item > root->data)
        root->right = insert(root, root->right, item);

    else
        return root;

    if(parent->color == 1)
        return root;
}

void insertNode(Node *root, int item)
{
    root = insert(NULL, root, item);
}

int main()
{
    Node *root = NULL;
    insertNode(root, 50);
}