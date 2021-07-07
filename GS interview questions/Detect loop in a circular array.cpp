bool dfs(int vertex, vector<int> adj[], vector<bool> &visited, vector<bool> &recstack){
        visited[vertex] = true;
        recstack[vertex] = true;
        cout << "vertex " << vertex <<  endl;
        for(int i = 0; i < visited.size(); i++){
            cout << visited[i];
        }
        cout << "\n";
        for(int i = 0; i < visited.size(); i++){
            cout << recstack[i];
        }
        cout << "\n";
        vector<int>::iterator i;
        for(int i = 0; i < adj[vertex].size(); i++){
            cout << "next vertex" << adj[vertex][i] << endl;
            if(!visited[adj[vertex][i]] && dfs(adj[vertex][i], adj, visited, recstack))
                return true;
            else if(visited[adj[vertex][i]] && recstack[adj[vertex][i]]){
                cout << "vertex" << vertex << endl;
                cout << adj[vertex][i] << endl;
                return true;
            }
        }
        /*for(i = adj[vertex].begin(); i != adj[vertex].end(); i++){
            if(!visited[*i] && dfs(*i, adj, visited, recstack))
                return true;
            else if(visited[*i] && recstack[*i])
                return true;
        }*/
        recstack[vertex] = false;
        return false;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<int> adj[n];
        for(int i = 0; i < n; i++){
            cout << "i " << i << " " << (i + nums[i] + n)%n <<endl;
            if(i != ((i + nums[i] + n)%n))        
                adj[i].push_back((i + nums[i] + n)%n);
        }
        vector<bool> visited(n, false);
        vector<bool> recstack(n, false);
        for(int i = 0; i < n ; i++){
            if(!visited[i])
                return dfs(i, adj, visited, recstack);
        }
        cout << "hello" << endl;
        return true;
    }
	

/* 2nd solution */
bool dfs(vector<int>& nums,vector<int>& vis,unordered_set<int>& s, int ind, bool dir)
    {
        int n = nums.size();
        if(dir && nums[ind]<0)return false;
        if(!dir && nums[ind]>0)return false; 
        if(nums[ind]%n==0 || vis[ind])return false;
        
        if(s.find(ind)!= s.end())return true;
        
        s.insert(ind);
        int nxt = (ind + (nums[ind])%n +n )%n;
        
        return dfs(nums, vis, s,nxt, dir );
        
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        vector<int> vis(n, 0);
        
        bool ans = false;
        
        for(int i=0;i<n;i++)
        {
            unordered_set<int> s;
            if(!vis[i])
            {
                if(nums[i]%n==0){vis[i]= true; continue;}
                
                if(nums[i]>0)
                    ans = dfs(nums, vis, s, i, true );
                else
                    ans = dfs(nums, vis, s, i, false );
                cout<<ans<<" ";
            }
            if(ans)return true;
            for(auto x: s)vis[x]=1;
        }
        return ans;
    }