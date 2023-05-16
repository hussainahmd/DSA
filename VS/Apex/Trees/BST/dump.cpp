#include"C:\Users\Hussain\Desktop\DSA\VS\Apex\Trees\base.h"

void removeMinFromRightSubtree(Node *root){
    Node *parentOfLeftMost = root;
    Node *leftMost = root->right; //leftmost from right subtree

    while(leftMost->left != NULL){
        parentOfLeftMost = leftMost;
        leftMost = leftMost->left;
    }
    root->data = leftMost->data;

    if(parentOfLeftMost->left == leftMost)
        parentOfLeftMost->left = leftMost->right;
    else
        parentOfLeftMost->right = leftMost->right;
    
    delete leftMost;
}

void removeUtil(Node *prev, Node *root, int key){
    if(!root)
        return;

    if(key < root->data)
        removeUtil(root, root->left, key);

    else if(key > root->data)
        removeUtil(root, root->right, key);

    else{
        if(!root->left && !root->right){
            delete root;
            root = NULL;
            return;
        }
        
        if(prev == NULL){
            if(!root->left){
                Node *temp = root;
                root = root->right;
                delete temp;
                return;
            }
            if(!root->right){
                Node *temp = root;
                root = root->left;
                delete temp;
                return;
            }
            else{
                Node *temp = minValueNode(root->right);
                root->data = temp->data;
                removeUtil(root, root->right, temp->data);
                return;
            }
        }

        if(!root->left){
            if(prev->right && prev->right->data == root->data)
                prev->right = root->right;
            else //if(prev->left && prev->left->data == root->data)
                prev->left = root->right;

            delete root;
            return;
        }
        if(!root->right){
            if(prev->right && prev->right->data == root->data)
                prev->right = root->left;
            else //if(prev->left && prev->left->data == root->data)
                prev->left = root->left;

            delete root;
            return;
        }
        else{
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            removeUtil(root, root->right, temp->data);
            return;
        }
    }

}

void remove(Node *&root, int key){
    if(!root){
        cout << "Error! NULL tree\n";
        return;
    }
    Node *p = NULL;
    removeUtil(NULL, root, key);
    //cout << "Key not found!\n";
}
