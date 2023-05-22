#include "C:\Users\Hussain\Desktop\DSA\VS\Apex\Trees\funcs_BT_BST.h"

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

void removeNodeItr(Node *&root, int key)
{
    if (!root)
    {
        cout << "Tree is empty!\n";
        return;
    }
    Node *parent = NULL, *current = root;

    while (current != NULL)
    {
        if (key < current->data)
        {
            parent = current;
            current = current->left;
        }

        else if (key > current->data)
        {
            parent = current;
            current = current->right;
        }
        else
            break; // Element found in the tree at current pointer
    }
    if (current == NULL)
    {
        cout << "Key not found\n";
        return;
    }
    // Case1: current has no left child
    // will also work for if no children
    if (current->left == NULL)
    {
        Node *temp = current;
        if (parent == NULL)
        {
            root = current->right;
        }
        else
        {
            if (key < parent->data)
                parent->left = current->right;
            else
                parent->right = current->right;
        }
        delete temp;
    }
    // Case2: current has no right child
    else if (current->right == NULL)
    {
        Node *temp = current;
        if (parent == NULL)
        {
            root = current->left;
        }
        else
        {
            if (key < parent->data)
                parent->left = current->left;
            else
                parent->right = current->left;
        }
        delete temp;
    }
    // Case3: current has both children
    else
    {
        // Locate the rightmost node in the left subtree of
        // the current node and also its parent
        Node *parentOfRightMost = current;
        Node *rightMost = current->left;

        while (rightMost->right != NULL)
        {
            parentOfRightMost = rightMost;
            rightMost = rightMost->right; // keep going right
        }
        current->data = rightMost->data;

        if(parentOfRightMost->right == rightMost)
            parentOfRightMost->right = rightMost->left;
        else
            parentOfRightMost->left = rightMost->left;

        delete rightMost;
    }
}

// if root has both childs then replace minValueNode from right subtree and delete it
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
        // if (root->left == NULL || root->right == NULL)
        // {
        //     Node* temp = root->left ? root->left : root->right;

        //     if (temp == NULL) {
        //         temp = root;
        //         root = NULL;
        //     } else {
        //         *root = *temp;
        //     }
        //     delete temp;
        // }
        
        // case if root has right child
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // case if root has left child
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // case if root has both children
        Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = removeNode(root->right, temp->data);
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

    root = removeNode(root, 50);
    root = removeNode(root, 80);
    root = removeNode(root, 30);
    // removeNodeItr(root, 50);
    // removeNodeItr(root, 80);
    // removeNodeItr(root, 30);
    print(root);

    cout << "\n";
    cout << "***************************";
    cout << "\n";

    // root = removeNode(root, 60);
    // root = removeNode(root, 70);
    removeNodeItr(root, 60);
    removeNodeItr(root, 70);

    print(root);
    cout << "inorder :\n";
    inOrder(root);
    cout << "\n";
}
