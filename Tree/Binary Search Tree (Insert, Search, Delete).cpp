// A C Program to demonstrate adjacency list
// representation of graphs
#include <iostream>
using namespace std;

struct BSTNode{
    int val;
    BSTNode* left;
    BSTNode* right;
};

struct BSTNode* createNode(int val){
    struct BSTNode* temp = new BSTNode;
    temp->val = val;
    temp->left = NULL;
    temp->right =  NULL;
    return temp;
}

void printBST(BSTNode* root){
    if(!root) return;
    printBST(root->left);
    cout << root->val << " -> ";
    printBST(root->right);
}

BSTNode* Insert(BSTNode* root, int data){
    if(!root){
        return createNode(data);
    }
    if(root->val > data){
        root->left = Insert(root->left, data);
    }
    else{
        root->right = Insert(root->right, data);
    }
    return root;
}

BSTNode* Search(BSTNode* root, int data){
    if(!root){
        return NULL;
    }
    if(root->val == data){
        return root;
    }
    if(root->val > data){
        return Search(root->left, data);
    }
    else{
        return Search(root->right, data);
    }
}

BSTNode* inorderSucc(BSTNode* root){
    BSTNode* temp = root;
    if(temp && temp->left){
        temp = temp->left;
    }
    return temp;
}

BSTNode* deleteNode(BSTNode* root, int data){
    if(!root) return NULL;
    if(root->val > data){
        root->left = deleteNode(root->left, data);
    }
    else if(root->val < data){
        root->right = deleteNode(root->right, data);
    }
    else{
        if(root->left == NULL && root->right == NULL){ //Leaf node case, nodes with 0 child
            return NULL;
        }
        //Node having 1 children
        if(root->left == NULL){
            BSTNode* temp = root->right;
            delete(root);
            return temp;
        }
        else if(root->right == NULL){
            BSTNode* temp = root->left;
            delete(root);
            return temp;
        }
        //Node having both children
        BSTNode* temp = inorderSucc(root->right);
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

// Driver program to test above functions
int main()
{
	BSTNode* root = NULL;
    root = Insert(root, 8);
    Insert(root, 3);
    Insert(root, 1);
    Insert(root, 6);
    Insert(root, 7);
    Insert(root, 10);
    Insert(root, 14);
    Insert(root, 4);
 
    printBST(root);
    BSTNode* temp = Search(root, 3);
    if(temp){
        cout << "\nKey Found\n";
    }
    else{
        cout << "\nKey not Found\n";
    }
    deleteNode(root, 3);
    printBST(root);
    temp = Search(root, 3);
    if(temp){
        cout << "\nKey Found\n";
    }
    else{
        cout << "\nKey not Found\n";
    }
    return 0;
}
