void leftViewUtil(Node* root, int level, int &maxlevel, vector<int> &res){
    if(!root) return;
    if(level > maxlevel){
        maxlevel = level;
        res.push_back(root->data);
    }
    leftViewUtil(root->left, level + 1, maxlevel, res);
    leftViewUtil(root->right, level + 1, maxlevel, res);
}
vector<int> leftView(Node *root)
{
    //if(!root) return ;
    int max_level = 0;
    vector<int> res;
    leftViewUtil(root, 1, max_level, res);
    return res;
}

/* Time Complexity = O(n)
   Space Complexity = O(h) space for call stack, h = height of tree
*/

vector<int> leftView(Node *root)
{
    //if(!root) return ;
    queue<Node*> q;
    q.push(root);
    vector<int> res;
    while(!q.empty()){
        int n = q.size();
        for(int i = 0; i < n ; i++){
            Node* temp = q.front();
            q.pop();
            if(i == 0){
                res.push_back(temp->data);
            }
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return res;
}	
/* Time Complexity = O(n)
   Space Complexity = O(n) 
*/