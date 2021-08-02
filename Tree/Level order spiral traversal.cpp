class Solution {
public:
    /*
    void getzigzag(TreeNode* root, int level, vector<vector<int>> &ans, bool dir){
        if(!root) return;
        if(level == ans.size()) ans.push_back({});
        ans[level].push_back(root->val);
        dir = !dir;
        if(dir){
            if(root->left)
                getzigzag(root->left, level + 1, ans, dir);
            if(root->right)
                getzigzag(root->right, level + 1, ans, dir);
        }
        else{
            if(root->right)
                getzigzag(root->right, level + 1, ans, dir);
            if(root->left)
                getzigzag(root->left, level + 1, ans, dir);
        }
        return;
    }
    */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans = {};
        /*
        int level = 0;
        bool dir = true;
        getzigzag(root, level, ans, dir);
        */
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        while(!q.empty()){
            int n = q.size();
            vector<int> l;
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                l.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(level % 2 == 0)
                reverse(l.begin(), l.end());
            ans.push_back(l);
            level++;
        }
        return ans;
    }
};