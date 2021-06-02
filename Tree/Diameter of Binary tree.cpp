#include <bits/stdc++.h>
using namespace std;

struct node{
    struct node* left;
    struct node* right;
    int val;
};

struct node* createNode(int data){
    struct node* temp  = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->val = data;
    return temp;
}

int height(struct node* root){
    if(!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return max(lh, rh) + 1;
}

//Complexity of this function is O(n^2)
int diameter(struct node* root){
    if(!root) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    int ret1 = max(ld, rd);
    int ret2  = lh + rh + 1;
    return max(ret1, ret2);
}

int height_On(struct node* root, int &ans){
    if(!root) return 0;
    int lh = height_On(root->left, ans);
    int rh = height_On(root->right, ans);
    //update ans because diameter is nothing but max of lh+rh+1 between each node
    ans = max(ans, lh + rh + 1);
    return 1 + max(lh, rh);
}

//Complexity of this function is O(n)
int diameter_On(struct node* root){
    if(!root) return 0;
    int ans = INT_MIN;
    height_On(root, ans);
    return ans;
}


int main()
{
 
    /* Constructed binary tree is
            1
            / \
        2     3
        / \
    4     5
    */
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout << "Diameter of the given binary tree with O(n^2) time complexity is " <<
        diameter(root);
    cout<< endl;
    cout << "Diameter of the given binary tree with O(n) time complexity is " <<
        diameter_On(root);
 
    return 0;
}