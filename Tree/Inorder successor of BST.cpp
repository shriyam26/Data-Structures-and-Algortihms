// C program for above approach
#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* minValue(struct node* node);

/*
If right subtree of node is not NULL, then succ lies in right subtree. Do the following. 
Go to right subtree and return the node with minimum key value in the right subtree.
If right subtree of node is NULL, then start from the root and use search-like technique. Do the following. 
Travel down the tree, if a node’s data is greater than root’s data then go right side, otherwise, go to left side.
*/
struct node* inOrderSuccessor(struct node* root, struct node* n)
{
    if (n->right != NULL)
        return minValue(n->right);
 
    struct node* succ = NULL;
    
    while (root != NULL)
    {
        if (n->data < root->data)
        {
            succ = root;
            root = root->left;
        }
        else if (n->data > root->data)
            root = root->right;
        else
            break;
    }
 
    return succ;
}

struct node* minValue(struct node* node)
{
    struct node* current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}
 
struct node* newNode(int data)
{
    struct node* node = (struct node*)
        malloc(sizeof(
            struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 
struct node* insert(struct node* root,
                    int data)
{
    if(!root){
        return newNode(data);
    }
    if(root->data > data){
        root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}
 
/* Driver program to test above functions*/
int main()
{
    struct node *root = NULL, *temp, *succ;
 
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    temp = root->left->right->right;
     
    succ = inOrderSuccessor(root, temp);
    if (succ != NULL)
        printf(
            "\n Inorder Successor of %d is %d ",
            temp->data, succ->data);
    else
        printf("\n Inorder Successor doesn't exit");
    return 0;
}