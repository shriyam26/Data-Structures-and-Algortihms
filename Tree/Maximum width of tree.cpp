// Recursive CPP program for level order traversal of Binary Tree
#include <bits/stdc++.h>
using namespace std;
 
class node
{
    public:
    int data;
    node* left, *right;
};
 
int printCurrentLevel(node* root, int level);
int height(node* node);
node* newNode(int data);

int printLevelOrder(node* root)
{
    int h = height(root);
    int i;
    int maxWidth = 0;
    int width;
    for (i = 1; i <= h; i++){
        width = printCurrentLevel(root, i);
        if(width > maxWidth) maxWidth = width;
    }    
    return maxWidth;
	/*
	Time Complexity: O(n^2) where n is the number of nodes in the binary tree 
	Space Complexity: O(n) where n is the number of nodes in the binary tree 
	*/
}

int printLevelOrder(node *root)
{
    if (root == NULL)  return 0;
    queue<node *> q;
    q.push(root);
    int width = 0, maxWidth = 0;
    while (q.empty() == false)
    {
        width = q.size();
        if(maxWidth < width) maxWidth = width;
        while(width--){
            node *Node = q.front();
            q.pop();
            if (Node->left != NULL)
                q.push(Node->left);
            if (Node->right != NULL)
                q.push(Node->right);
        }
    }
    return maxWidth;
	/*
	Time Complexity: O(n) where n is the number of nodes in the binary tree 
	Space Complexity: O(n) where n is the number of nodes in the binary tree 
    */
}

 
int printCurrentLevel(node* root, int level)
{
    if (root == NULL)
        return 0;
    if (level == 1)
        return 1;
    else if (level > 1)
    {
        return (printCurrentLevel(root->left, level-1) + 
        printCurrentLevel(root->right, level-1));
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
 
    cout << "width of the tree is \n";
    cout << printLevelOrder(root);
 
    return 0;
}