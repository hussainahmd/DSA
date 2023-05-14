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

void insert(Node *&root, int item)
{
    if (!root)
    {
        root = new Node(item);
        return;
    }

    if (item < root->data)
        insert(root->left, item);

    if (item > root->data)
        insert(root->right, item);
}

void insertItr(Node *&root, int item)
{
    if(!root){
        root = new Node(item);
        return;
    }

    Node *previous, *current = root;
    while(current != NULL)
    {
        if(item < current->data)
            current = current->left;
        
        if(item > current->data)
            current = current->right;
    }

    if(item < previous->data)
        previous->left = new Node(item);
    
    if(item > previous->data)
        previous->right = new Node(item);
}

Node *minValueNode(Node *&root)
{
    Node *current = root;

    // Loop down to find the leftmost leaf
    while (current != NULL && current->left != NULL)
        current = current->left;

    return current;
}

Node *removeNode(Node *root, int key)
{
    if (!root)
        return root;

    if (key < root->data)
        root->left = removeNode(root->left, key);

    else if (key > root->data)
        root->right = removeNode(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}

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

int main(){
    Node *root = NULL;
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    cout << "\n-> Before deleting 70\n";
    cout << "preorder :\n";
    preOrder(root);

    cout << "\ninorder :\n";
    inOrder(root);

    cout << "\npostorder :\n";
    postOrder(root);
    cout << "\n";

    removeNode(root, 70);

    cout << "\n-> After deleting 70\n";
    cout << "preorder :\n";
    preOrder(root);

    cout << "\ninorder :\n";
    inOrder(root);

    cout << "\npostorder :\n";
    postOrder(root);
    cout << "\n\n";
}