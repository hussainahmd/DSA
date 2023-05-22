#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

pair<int, bool> isHeightBalanced(Node* node) {
    if (node == nullptr)
        return make_pair(0, true);

    pair<int, bool> leftSubtree = isHeightBalanced(node->left);
    pair<int, bool> rightSubtree = isHeightBalanced(node->right);

    int leftHeight = leftSubtree.first;
    int rightHeight = rightSubtree.first;

    int currentHeight = max(leftHeight, rightHeight) + 1;
    int heightDiff = abs(leftHeight - rightHeight);

    if (heightDiff <= 1 && leftSubtree.second && rightSubtree.second)
        return make_pair(currentHeight, true);

    return make_pair(currentHeight, false);
}

int main() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->left->left->left = createNode(4);

    pair<int, bool> result = isHeightBalanced(root);

    if (result.second)
        cout << "The tree is height-balanced.\n";
    else
        cout << "The tree is not height-balanced.\n";

    cout << "The height of the tree is: " << result.first << "\n";

    return 0;
}
