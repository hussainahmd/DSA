#include <bits/stdc++.h>
#include "base.h"
using namespace std;

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

    root->height = update_height(root); // max of (leftH, rightH) + 1

    int balanace_factor = balance_factor(root);

    if (balanace_factor > 1)
    {
        if (item < root->left->data) // if item was inserted left->left
        {
            return rotate_right(root);
        }
        else // if item was inserted left->right
        {
            root->left = rotate_left(root->left);
            return rotate_right(root);

            // return rotate_left_right(root);
        }
    }

    if (balanace_factor < -1)
    {
        if (item > root->right->data) // if item was inserted right->right
        {
            return rotate_left(root);
        }
        else // if item was inserted right->left
        {
            root->right = rotate_right(root->right);
            return rotate_left(root);

            // return rotate_right_left(root);
        }
    }
    return root;
}

//*******************************************************************

int main()
{
    Node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 70);
    root = insert(root, 10);
    root = insert(root, 15);

    // root = insert(root, 50);
    // root = insert(root, 30);
    // root = insert(root, 70);
    // root = insert(root, 20);
    // root = insert(root, 55);
    // root = insert(root, 80);
    // root = insert(root, 75);
    // root = insert(root, 90);
    // root = insert(root, 72);
    // root = insert(root, 76);
    // root = insert(root, 77);

    answer *ans = is_Balanced(root);
    if (ans->balanced)
        cout << "\nThe tree is height-balanced.\n";
    else
        cout << "The tree is not height-balanced.\n";

    cout << "The height of the tree is: " << ans->height;
    cout << "\n\n******************************\n";

    print(root);
}