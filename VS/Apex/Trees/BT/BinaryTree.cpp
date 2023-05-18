#include <queue>
#include "C:\Users\Hussain\Desktop\DSA\VS\Apex\Trees\funcs_BT_BST.h"

//******************************************************************//

void insert(Node *&root, int item)
{
    if (!root)
    {
        root = new Node(item);
        return;
    }
    Node *temp;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (!temp->left)
        {
            temp->left = new Node(item);
            return;
        }
        else
            q.push(temp->left);

        if (!temp->right)
        {
            temp->right = new Node(item);
            return;
        }
        else
            q.push(temp->right);
    }
}

int main()
{
    Node *root = new Node(0);

    insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);

    int h = height(root);
    cout << "\nHeight : " << h << "\n";
    cout << "Inorder : [ ";
    inOrder(root);
    cout << "]\n";
    cout << "Levelorder :\n";
    levelOrder(root);
    cout << "\n";
    cout << "Non Leaf nodes : ";
    nonLeafNodes(root);
    cout << "\n";
    cout << "Leaf nodes : ";
    leafNodes(root);
    cout << "\n";

    print(root);
    printRight(root);
}