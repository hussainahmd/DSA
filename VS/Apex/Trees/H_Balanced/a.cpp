#include <bits/stdc++.h>
#include "base.h"
using namespace std;

//*******************************************************************
struct answer
{
    int height;
    bool balanced;

    answer(int a, bool b)
    {
        height = a;
        balanced = b;
    }
};

answer *is_Balanced(Node *root)
{
    if (root == NULL)
        return new answer(0, true);

    answer *left_subtree = is_Balanced(root->left);
    answer *right_subtree = is_Balanced(root->right);

    int left_height = left_subtree->height;
    int right_height = right_subtree->height;

    int current_height = max(left_height, right_height) + 1;
    int height_diff = abs(left_height - right_height);

    if (height_diff <= 1 && left_subtree->balanced && right_subtree->balanced)
        return new answer(current_height, true);

    return new answer(current_height, false);
}

//*******************************************************************

int getHeight(Node *root)
{
    if (root == NULL)
        return 0;

    return root->height;
}

int balance_factor(Node *root)
{
    if (root == NULL)
        return 0;

    return getHeight(root->left) - getHeight(root->right);
}

int update_height(Node *root)
{
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

//*******************************************************************

Node *insert(Node *root, int item)
{
    if (root == NULL)
        return new Node(item);

    if (item < root->data)
        root->left = insert(root->left, item);

    else if (item > root->data)
        root->right = insert(root->right, item);

    else
        return root;

    root->height = update_height(root); //max of (leftH, rightH) + 1

    int balanace_factor = balance_factor(root);

    if (balanace_factor > 1)
    {
        if (item < root->left->data) // if item was inserted left->left
        {
            Node *new_root = root->left;
            root->left = new_root->right;
            new_root->right = root;

            root->height = update_height(root);
            new_root->height = update_height(new_root);
            return new_root;
        }
        else // if item was inserted left->right
        {
            Node *new_root = root->left->right;
            new_root->left = root->left;
            root->left = new_root->right;
            new_root->right = root;
            new_root->left->right = NULL;
            print(new_root);

            root->height = update_height(root);
            new_root->left->height = update_height(new_root->left);
            new_root->height = update_height(new_root);
            return new_root;
        }
    }

    if (balanace_factor < -1)
    {
        if (item > root->right->data) // if item was inserted right->right
        {
            Node *new_root = root->right;
            root->right = new_root->left;
            new_root->left = root;

            root->height = update_height(root);
            new_root->height = update_height(new_root);
            return new_root;
        }
        else // if item was inserted right->left
        {
            Node *new_root = root->right->left;
            new_root->right = root->right;
            root->right = new_root->left;
            new_root->left = root;
            new_root->right->left = NULL;
            print(new_root);

            root->height = update_height(root);
            new_root->right->height = update_height(new_root->right);
            new_root->height = update_height(new_root);
            return new_root;
        }
    }
    return root;
}

//*******************************************************************

int main()
{
    // Node *root = new Node(50);
    // root->left = new Node(20);
    // root->right = new Node(70);
    // root->left->left = new Node(10);
    // root->left->right = new Node(15);
    
    // root->right->right = new Node(90);
    // root->right->left = new Node(80);
    //root->left->left->left = new Node(5);

    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 70);
    root = insert(root, 10);
    root = insert(root, 15);

    answer *ans = is_Balanced(root);
    if (ans->balanced)
        cout << "\nThe tree is height-balanced.\n";
    else
        cout << "The tree is not height-balanced.\n";

    cout << "The height of the tree is: " << ans->height;
    cout << "\n\n******************************\n";

    print(root);
}