//Clearly, the presence of a cycle in the graph shows us that a proper ordering of prerequisites is not possible at all. Intuitively, it is not possible to //have e.g. two subjects S1 and S2 prerequisites of each other. Similar ideology applies to a larger cycle in the graph like we have above.

class Solution {
public:
    bool dfsUtil(int v, vector<bool> &visited, vector<bool> &recstack, list<int> adj[], stack<int> &s){
        visited[v] = true;
        recstack[v] = true;
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); i++){
            if(!visited[*i]){
                if(dfsUtil(*i, visited, recstack, adj, s))
                    return true;
            }
            else if(recstack[*i])
                return true;
        }
        recstack[v] = false;
        s.push(v);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<bool> recstack(numCourses, false);
        list<int> adj[numCourses];
        vector<int> res;
        stack<int> s;
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                if(dfsUtil(i, visited, recstack, adj, s)) //check if cycle is present or not, if present return empty
                    return {};
            }
        }
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
};

-------------------------------------------------------------------

/* BFS Solution */

/* Kahn's Algo */

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> in(numCourses,0);
        vector<int> *adj = new vector<int>[numCourses];
        for(auto edge : prerequisites){
          adj[edge[1]].push_back(edge[0]);
          in[edge[0]]++;
        }
        vector<int> res;
         queue<int> q;
        for(int i=0; i< numCourses;i++) {
          if(in[i] ==0)
              q.push(i);
        }
       while(!q.empty()) {
           int val = q.front();
           q.pop();
           res.push_back(val);
           for(auto i = adj[val].begin();i!=adj[val].end();i++) {
               in[*i]--;
               if(in[*i] == 0)
                   q.push(*i);
           }
           numCourses--;
       }
       if(numCourses == 0)
           return res;
       return {};
    }
    
};