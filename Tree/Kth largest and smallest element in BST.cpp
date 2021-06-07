/*
Program to find Kth smallest element in binary tree using inorder traversal.
The Inorder Traversal of a BST traverses the nodes in increasing order. So the idea is to traverse the tree in Inorder. While traversing, keep track of the count of the nodes visited. If the count becomes k, print the node.
*/
void kthSmallestUtil(Node* root, int &k, int &c, int &res){
        if(!root || c > k) return;
        kthSmallestUtil(root->left, k, c, res);
        c++;
        if(c == k) {
            res = root->data;
            return;
        }    
        kthSmallestUtil(root->right, k, c, res);
    }
int KthSmallestElement(Node *root, int K)
{
    if(!root) return -1;
    int c = 0;
    int res = -1;
    kthSmallestUtil(root, K, c, res);
    return res;
}    

/* O(n) time and O(h) auxiliary space */

//For Kth largest element just do reversal of inorder traversal, first visit right nodes, then root and then left.