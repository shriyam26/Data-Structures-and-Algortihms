// Kth Smallest element in a BST

/*
The Inorder Traversal of a BST traverses the nodes in increasing order. So the idea is to traverse the tree in Inorder. While traversing, keep track of the count of the nodes visited. If the count becomes k, print the node.
*/

class Solution {
public:
    TreeNode* kthSmallestUtil(TreeNode* root, int &k){
        if(!root) return 0;
        cout << root->val << endl;
        TreeNode* left = kthSmallestUtil(root->left, k);
        if(left != nullptr)
            return left;
        k--;
        if(k == 0)
            return root;
        return kthSmallestUtil(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* res = kthSmallestUtil(root, k);
        return res->val;
    }
};

// Time Complexity = O(n) and Space = O(h) 

---------------------------------------------------------

// Kth Largest element in a BST

/*
Approach: 
 

The idea is to do reverse inorder traversal of BST. Keep a count of nodes visited.
The reverse inorder traversal traverses all nodes in decreasing order, i.e, visit the right node then centre then left and continue traversing the nodes recursively.
While doing the traversal, keep track of the count of nodes visited so far.
When the count becomes equal to k, stop the traversal and print the key.
*/

class Solution
{
    public:
    void kthLargestUtil(Node* root, int &k, int &c, int &res){
        if(!root || c > k) return;
        kthLargestUtil(root->right, k, c, res);
        c++;
        if(c == k) {
            res = root->data;
            return;
        }    
        kthLargestUtil(root->left, k, c, res);
    }
    int kthLargest(Node *root, int K)
    {
        if(!root) return -1;
        int c = 0;
        int res = -1;
        kthLargestUtil(root, K, c, res);
        return res;
    }
};