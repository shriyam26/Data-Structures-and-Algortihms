/*
The idea is to do something similar to vertical Order Traversal. Like vertical Order Traversal, we need to put nodes of same horizontal distance together. We do a level order traversal so that the topmost node at a horizontal node is visited before any other node of same horizontal distance below it. Hashing is used to check if a node at given horizontal distance is seen or not. 
*/

vector<int> topView(Node *root)
    {
        vector<int> ans;
        
        // base case
        if(root == NULL){
            return ans;
        }
    
        Node *temp = NULL;
        //creating empty queue for level order traversal.
        queue<pair<Node *, int>> q;
        //creating a map to store nodes at a particular horizontal distance.
        map<int, int> mp;
    
        q.push({root, 0});
        while(!q.empty())
        {
    
            temp = q.front().first;
            int d = q.front().second;
            q.pop();
            
            //storing temp->data in map.
            if(mp.find(d) == mp.end()){
                mp[d] = temp->data;
            }
            
            //if left child of temp exists, pushing it in
            //the queue with the horizontal distance.
            if(temp->left){
                q.push({temp->left, d-1});
            }
            //if right child of temp exists, pushing it in
            //the queue with the horizontal distance.
            if(temp->right){
                q.push({temp->right, d+1});
            }
        }
        //traversing the map and storing the nodes in list 
        //at every horizontal distance.
        for(auto it = mp.begin(); it != mp.end(); it++){
            ans.push_back(it->second);
        }
        //returning the output list.
        return ans;
    }