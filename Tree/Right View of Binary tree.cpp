class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                if(n == 0){
                    res.push_back(temp->val);
                }
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return res;
    }
};
/* Just access the nodes in queue in reverse order
   Time Complexity = O(n)
   Space Complexity = O(n) 
*/

class Solution {
public:
    void rightViewUtil(TreeNode* root, vector<int> &res, int level, int &maxl){
        if(!root) return;
        if(level > maxl){
            maxl = level;
            res.push_back(root->val);
        }
        rightViewUtil(root->right, res, level+1, maxl);
        rightViewUtil(root->left, res, level+1, maxl);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        int maxl = 0;
        rightViewUtil(root, res, 1, maxl);
        return res;
    }
};

/* Just call right child before than left.
   Time Complexity = O(n)
   Space Complexity = O(h) space for call stack, h = height of tree
*/