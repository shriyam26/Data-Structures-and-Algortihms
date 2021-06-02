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
//This method is a bit like binary search
/*bool isBSTUtil(BSTNode* root, BSTNode* left, BSTNode* right){
    if(!root) return 1;
    
    // if left node exist then check it has
    // correct data or not i.e. left node's data
    // should be less than root's data
    
    if(left && root->val <= left->val )return 0;
    
    // if right node exist then check it has
    // correct data or not i.e. right node's data
    // should be greater than root's data
    
    if(right && root->val >= right->val) return 0;
    
    // check recursively for every node.
    return isBSTUtil(root->left, left, root) && isBSTUtil(root->right, root, right);
}*/

// This method uses inorder traversal of BST
bool isBSTUtil(BSTNode* root, BSTNode* &prev){
    if(!root) return 1;
    if(!isBSTUtil(root->left, prev)) return 0;
    if(prev && root->val <= prev->val) return 0;
    prev = root;
    return isBSTUtil(root->right, prev);
}

bool isBST(BSTNode* root){
    //return isBSTUtil(root, NULL, NULL);
    
    
    //While doing In-Order traversal, we can keep track of previously visited node. If the value of the currently visited node is less than the previous value, //then tree is not BST
    BSTNode* prev = NULL;
    return isBSTUtil(root, prev);
    
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
    /*
    root              = createNode(3);
    root->left        = createNode(2);
    root->right       = createNode(5);
    root->left->left  = createNode(1);
    root->left->right = createNode(4);
    */
    printBST(root);
    if(isBST(root)){
        cout << "\nThis is a BST";
    }
    else{
        cout << "\nThis is not a BST";
    }
    return 0;
}
