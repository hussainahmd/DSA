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

//******************************************************************//

Node *rotate_right(Node *root)
{
    Node *new_root = root->left;
    root->left = new_root->right;
    new_root->right = root;

    root->height = update_height(root);
    new_root->height = update_height(new_root);
    return new_root;
}

Node *rotate_left(Node *root)
{
    Node *new_root = root->right;
    root->right = new_root->left;
    new_root->left = root;

    root->height = update_height(root);
    new_root->height = update_height(new_root);
    return new_root;
}

//******************************************************************//

Node *rotate_left_right(Node *root)
{
    Node *new_root = root->left->right;
    new_root->left = root->left;
    root->left = new_root->right;
    new_root->right = root;
    new_root->left->right = NULL;

    root->height = update_height(root);
    new_root->left->height = update_height(new_root->left);
    new_root->height = update_height(new_root);
    return new_root;
}

Node *rotate_right_left(Node *root)
{
    Node *new_root = root->right->left;
    new_root->right = root->right;
    root->right = new_root->left;
    new_root->left = root;
    new_root->right->left = NULL;

    root->height = update_height(root);
    new_root->right->height = update_height(new_root->right);
    new_root->height = update_height(new_root);
    return new_root;
}


//******************************************************************//

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

//******************************************************************//