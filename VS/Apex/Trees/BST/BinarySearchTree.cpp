#include "C:\Users\Hussain\Desktop\DSA\VS\Apex\Trees\base.h"

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
    if (!root)
    {
        root = new Node(item);
        return;
    }

    Node *previous, *current = root;
    while (current != NULL)
    {
        if (item < current->data)
            current = current->left;

        if (item > current->data)
            current = current->right;
    }

    if (item < previous->data)
        previous->left = new Node(item);

    if (item > previous->data)
        previous->right = new Node(item);
}

//*******************************************************************//

Node *removeNodeItr(Node *root, int key)
{
    if (!root)
    {
        cout << "Tree is empty!\n";
        return NULL;
    }
    Node *previous, *current = root;

    while (!current && current->data != key)
    {
        if (key < current->data)
            current = current->left;

        if (key > current->data)
            current = current->right;
    }
}

//if root has both childs then swap minValueNode from right subtree and delete it
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
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL && root->left != NULL)
        {
            //this is fine but not for the below case
            /* Node *temp = root->left;
            delete root;
            return temp;*/

            //if main(topmost) root->right is NULL then swap the max node from left subtree
            //else, normal case that is to remove from right subtree
            Node *temp = maxValueNode(root->left);
            root->data = temp->data;
            root->left = removeNode(root->left, temp->data);
            return root;
            
        }
        else if (root->right == NULL && root->left == NULL)
        {
            delete root;
            return NULL;
        }

        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data);
        return root;
    }
    return root;
}

int main()
{
    Node *root = NULL;
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    // insert(root, 59);
    // insert(root, 61);
    // insert(root, 35);
    // insert(root, 45);
    // insert(root, 19);
    // insert(root, 21);
    // insert(root, 79);
    // insert(root, 81);

    int h = height(root);
    cout << "\nHeight : " << h << "\n";
    print(root);

    cout << "\n";
    cout << "***************************";
    cout << "\n";

    cout << "inorder :\n";
    inOrder(root);
    cout << "\n\n";

    removeNode(root, 50);
    //removeNode(root, 80);
    //root = removeNode(root, 30);

    print(root);
    cout << "inorder :\n";
    inOrder(root);
    cout << "\n";
}