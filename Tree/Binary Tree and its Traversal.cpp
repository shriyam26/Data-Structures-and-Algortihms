/*

1. Why do we use trees?
	-> They are used in heirarchial system, such as directory system.
	-> Trees (with some ordering e.g., BST) provide moderate access/search (quicker than Linked List and slower than arrays). 
	-> Trees provide moderate insertion/deletion (quicker than Arrays and slower than Unordered Linked Lists). 
	-> Like Linked Lists and unlike Arrays, Trees don’t have an upper limit on number of nodes as nodes are linked using pointers.
	
2. Binary tree and its properties
	-> The maximum number of nodes at level ‘L’ of a binary tree is 2^L. (For root, L = 0, so node = 1)
	-> The Maximum number of nodes in a binary tree of height ‘h’ is 2^h – 1(if root is taken as h = 0, if h = 1 for root then 2^(h+1) - 1)
	-> In a Binary Tree with N nodes, minimum possible height or the minimum number of levels is? Log2(N+1)
	-> A Binary Tree with L leaves has at least | Log2L? |+ 1   levels 
	
3. Types of Binary tree
    -> Full Binary tree :- A Binary Tree is a full binary tree if every node has 0 or 2 children
             18
           /    \   
         15     20    
        /  \       
      40    50   
    /   \
   30   50
   
	-> Complete Binary Tree:- A Binary Tree is a Complete Binary Tree if all the levels are completely filled except possibly the last level and the last level has all keys as left as possible.
	           18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40
     /  \   /
    8   7  9 
	  
	-> Perfect Binary Tree:- A Binary tree is a Perfect Binary Tree in which all the internal nodes have two children and all leaf nodes are at the same level.
	           18
           /       \  
         15         30          => This tree is a Full, complete and perfect binary tree, all three.
        /  \        /  \
      40    50    100   40
	In a Perfect Binary Tree, the number of leaf nodes is the number of internal nodes plus 1   
	L = I + 1 Where L = Number of leaf nodes, I = Number of internal nodes.
	A Perfect Binary Tree of height h (where the height of the binary tree is the longest path from the root node to any leaf node in the tree, height of root node is 1) has 2^h – 1 node.

	-> Balanced Binary Tree:- A binary tree is balanced if the height of the tree is O(Log n) where n is the number of nodes

The different Types of traversal are:-

	Depth First Traversals: 
	(a) Inorder (Left, Root, Right) : In case of binary search trees (BST), Inorder traversal gives nodes in non-decreasing order
	(b) Preorder (Root, Left, Right) : Preorder traversal is used to create a copy of the tree. Preorder traversal is also used to get prefix expression on of an expression tree
	(c) Postorder (Left, Right, Root) : Postorder traversal is used to delete the tree. Postorder traversal is also useful to get the postfix expression of an expression tree
	Breadth First or Level Order Traversal : 1 2 3 4 5 
*/	
	
// C++ program for different tree DFS traversals
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
 
void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    cout << node->data << " ";
}
 
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    printPreorder(node->left);
    printPreorder(node->right);
}
 
int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
 
    cout << "\nPreorder traversal of binary tree is \n";
    printPreorder(root);
 
    cout << "\nInorder traversal of binary tree is \n";
    printInorder(root);
 
    cout << "\nPostorder traversal of binary tree is \n";
    printPostorder(root);
 
    return 0;
}


/*
Output: 

Preorder traversal of binary tree is
1 2 4 5 3 
Inorder traversal of binary tree is
4 2 5 1 3 
Postorder traversal of binary tree is
4 5 2 3 1


Time Complexity : O(n)

Auxiliary Space : If we don’t consider size of stack for function calls then O(1) otherwise O(h) where h is the height of the tree. 
The height of the skewed tree is n (no. of elements) so the worst space complexity is O(n) and height is (Log n) for balanced tree so the best space complexity is O(Log n).
*/


/*
Difference between Level Order Traversal and Depth First Traversal
It is evident from above points that extra space required for Level order traversal is likely to be more when tree is more balanced and extra space for Depth First Traversal is likely to be more when tree is less balanced.

How to Pick One?

1. Extra Space can be one factor (Explained above)
2. Depth First Traversals are typically recursive and recursive code requires function call overheads.
3. The most important points is, BFS starts visiting nodes from root while DFS starts visiting nodes from leaves. So if our problem is to search something that is more likely to closer to root, we would prefer BFS. And if the target node is close to a leaf, we would prefer DFS.
*/


// Recursive CPP program for level order traversal of Binary Tree
#include <bits/stdc++.h>
using namespace std;
 
class node
{
    public:
    int data;
    node* left, *right;
};

-------------------------------------------------------------
/* Leetcode solution */
class Solution {
public:
    void getCurrentLevel(TreeNode* root, int level, vector<vector<int>> &ans){
        if(!root) return;
        if(level == ans.size()) ans.push_back({});
        ans[level].push_back(root->val);
        if(root->left){
            getCurrentLevel(root->left, level + 1, ans);
        }
        if(root->right){
            getCurrentLevel(root->right, level + 1, ans);
        }
        return;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans  = {};
        getCurrentLevel(root, 0, ans);
        return ans;
    }
    
};
--------------------------------------------------- 
void printCurrentLevel(node* root, int level);
int height(node* node);
node* newNode(int data);

void printLevelOrder(node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
	/*
	Time Complexity: O(n^2) where n is the number of nodes in the binary tree 
	Space Complexity: O(n) where n is the number of nodes in the binary tree 
	*/
}

void printLevelOrder(Node *root)
{
    if (root == NULL)  return;
    queue<Node *> q;
    q.push(root);
 
    while (q.empty() == false)
    {
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
	/*
	Time Complexity: O(n) where n is the number of nodes in the binary tree 
	Space Complexity: O(n) where n is the number of nodes in the binary tree 
	*/
}
 
void printCurrentLevel(node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}

int height(node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lheight = height(node->left);
        int rheight = height(node->right);
        if (lheight > rheight)
        {
            return(lheight + 1);
        }
        else {
          return(rheight + 1);
        }
    }
}
 
node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
 
    return(Node);
}
 
/* Driver code*/
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
    cout << "Level Order traversal of binary tree is \n";
    printLevelOrder(root);
 
    return 0;
}