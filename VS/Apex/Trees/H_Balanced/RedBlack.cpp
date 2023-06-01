#include "RB_base.h"

Node* insertUtil(Node *root, int item)
{
    if(root == NULL)
    {
        return new Node(item);
    }

    if (item < root->data)
    {
        root->left = insertUtil(root->left, item);
        root->left->parent = root;
    }

    else if (item > root->data)
    {
        root->right = insertUtil(root->right, item);
        root->right->parent = root;
    }

    else
        return root;

    if(root->color == 1)
        return root;

    if(root->color == 0)
    {
        Node *sibling = getSibling(root);
        if(sibling == NULL || sibling->color == 1)
        {
            if(root->data > root->parent->data)
            {
                if(item > root->right->data) // right->right
                {
                    recolor(root);
                    recolor(root->parent);

                    rotate_left(root->parent);
                }
                else // right->left
                {
                    recolor(root->parent);
                    recolor(root->left);

                    rotate_right(root);
                    rotate_left(root->parent);
                }
            }
            else // if(root->data < root->parent->data)
            {
                if(item < root->right->data) // left->left
                {
                    recolor(root);
                    recolor(root->parent);

                    rotate_right(root->parent);
                }
                else // left->right
                {
                    recolor(root->parent);
                    recolor(root->right);

                    rotate_left(root);
                    rotate_right(root->parent);
                }
            }


        }
        else // sibling(root)->color == 0
        {
            root->color = 1;
            sibling->color = 1;

            // if parent of root is not the top root then recolor it
            if(root->parent->parent != NULL)
                recolor(root->parent);
        }
    }
}

void insert(Node *&root, int item)
{
    if(root == NULL){
        root = new Node(item);
        root->color = 1;
    }
    else
        root = insertUtil(root, item);
}


int main()
{
    Node *root = NULL;
    insert(root, 50);
}
