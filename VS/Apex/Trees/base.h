#include <bits/stdc++.h>
#include <stack>
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

void inOrder(Node *&root);
void postOrder(Node *&root);
void preOrder(Node *&root);
void levelOrder(Node *&root);
void invert(Node *&root);
int height(Node *&root);
int getMinCol(Node *&root);
int getcol(int h);
void print(Node *&root);
void printH(Node *&root);
void printLevel(Node *&root, int level, bool z);
void nonLeafNodes(Node *&root);
void leafNodes(Node *&root);
Node *minValueNode(Node *&root);
int totalNodes(Node *&root);

//******************************************************************//

void zigzag(Node *root, int count)
{
    if (!root)
        return;

    count++;
    cout << root->data << " ";
    if (count % 2)
        zigzag(root->left, count);

    else
        zigzag(root->right, count);

    // cout << root->data << " ";
}

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

int totalNodes(Node *&root)
{
    if (!root)
        return 0;

    return totalNodes(root->left) + totalNodes(root->right) + 1;
}

//******************************************************************//

void deleteAll(Node *&root)
{
    if (!root)
    {
        // cout << "Empty\n";
        return;
    }

    deleteAll(root->left);
    deleteAll(root->right);

    delete root;
    root = NULL;
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

void inorderItr(Node *root)
{
    stack<Node *> s;
    if (root)
        s.push(root);

    while (!s.empty())
    {
        Node *a = s.top();

        if (a->left)
        {
            s.push(a->left);
            a->left = NULL;
        }
        else
        {
            cout << a->data << " ";
            s.pop();

            if (a->right)
                s.push(a->right);
        }
    }
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

void preorderItr(Node *root)
{
    stack<Node *> s;
    if (root)
        s.push(root);

    while (!s.empty())
    {
        auto a = s.top();
        s.pop();

        cout << a->data << " ";
        if (a->right)
            s.push(a->right);

        if (a->left)
            s.push(a->left);
    }
}

void levelOrder(Node *&root)
{
    int h = height(root);
    for (int i = 1; i <= h; i++)
    {
        if(i % 2)
            printLevel(root, i, true);
        else
            printLevel(root, i, true); //false here for zigzag
        cout << "\n";
    }
}

void printLevel(Node *&root, int level, bool z)//bool for zigzag level order
{
    if (!root)
        return;

    if (level == 1)
    {
        cout << root->data << " ";
        return;
    }

    if (level > 1){
        if(z){
            printLevel(root->left, level - 1, z);
            printLevel(root->right, level - 1, z);
        }
        else{
            printLevel(root->right, level - 1, z);
            printLevel(root->left, level - 1, z);
        }
    }
}

//******************************************************************//

void leafNodes(Node *&root)
{
    if (!root)
        return;

    if (!root->left && !root->right)
        cout << root->data << " ";

    if (root->left)
        leafNodes(root->left);

    if (root->right)
        leafNodes(root->right);
}

void nonLeafNodes(Node *&root)
{
    if (!root)
        return;

    if (root->left || root->right)
        cout << root->data << " ";

    if (root->left)
        nonLeafNodes(root->left);

    if (root->right)
        nonLeafNodes(root->right);
}

//******************************************************************//

void invert(Node *&root)
{
    if (!root)
        return;

    invert(root->left);
    invert(root->right);

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

//******************************************************************//

int leftNodes(Node *&root)
{
    if (!root)
        return 0;
    return leftNodes(root->left) + 1;
}

int rightNodes(Node *&root)
{
    if (!root)
        return 0;
    return rightNodes(root->right) + 1;
}

int getMinCol(Node *&root)
{ // min col
    if (!root)
        return 0;

    int col = (leftNodes(root) + rightNodes(root)) + 1;
}

int getcol(int h)
{ // max columns w.r.t height
    if (h == 1)
        return 1;
    return getcol(h - 1) + getcol(h - 1) + 1;
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

void printHUtil(Node *&root, int **M, int col, int row, int height)
{
    if (!root)
        return;

    M[row][col] = root->data;
    printHUtil(root->left, M, col - pow(2, height - 2), row + 1, height - 1);
    printHUtil(root->right, M, col + pow(2, height - 2), row + 1, height - 1);
}

void printH(Node *&root)
{
    if (!root)
    {
        cout << "Error!\n";
        return;
    }
    int h = height(root);
    int col = getcol(h);

    int **M = new int *[h];
    for (int i = 0; i < h; i++)
    {
        M[i] = new int[col];
        for (int j = 0; j < col; j++)
        {
            M[i][j] = 0;
        }
    }

    printHUtil(root, M, col / 2, 0, h);

    for (int i = 0; i < h; i++)
    {

        for (int j = 0; j < col; j++)
        {

            if (M[i][j] == 0)
                cout << "  ";
            else
                cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

//******************************************************************//

void printRight(Node *&root)
{
    if (!root)
        return;

    cout << root->data << " ";
    printRight(root->right);
}

void rightViewUtil(Node *&root, int level, int *max_level)
{
    // Base Case
    if (!root)
        return;

    // If this is the last Node of its level
    if (*max_level < level)
    {
        cout << root->data << "\t";
        *max_level = level;
    }

    // Recur for right subtree first,
    // then left subtree
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}

// A wrapper over rightViewUtil()
void rightView(struct Node *&root)
{

    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}
