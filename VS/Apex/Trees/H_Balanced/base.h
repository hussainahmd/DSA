#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int height = 1;
    Node *left = NULL;
    Node *right = NULL;

    Node(int item)
    {
        data = item;
    }
};

//******************************************************************//

Node *minValueNode(Node *&root)
{
    Node *current = root;

    // Loop down to find the leftmost leaf
    while (current->left != NULL)
        current = current->left;

    return current;
}

Node *maxValueNode(Node *&root)
{
    Node *current = root;

    // Loop down to find the rightmost leaf
    while (current->right != NULL)
        current = current->right;

    return current;
}

//******************************************************************//

void inOrder(Node *&root)
{
    if (!root)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node *&root)
{
    if (!root)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void preOrder(Node *&root)
{
    if (!root)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//******************************************************************//

int height(Node *&root)
{
    if (!root)
        return 0;

    int leftH = height(root->left);
    int rightH = height(root->right);

    if (leftH > rightH)
        return leftH + 1;
    else
        return rightH + 1;
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