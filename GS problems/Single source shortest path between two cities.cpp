class Solution {
public:
    typedef pair<int, int> p;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n+1];
        for(auto node : flights){
            adj[node[0]].push_back({node[1], node[2]});
        }
        queue<pair<int,p > > q;
        q.push({src, {0, 0}});
        int price[n+1];
        for(int i = 0; i <= n; i++){
            price[i] = INT_MAX;
        }
        price[src] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int distance = q.front().second.first;
            int cash = q.front().second.second;
            q.pop();
            for(auto v : adj[node]){
                int neededMoney = v.second;
                int dest = v.first;
                if((price[dest] > cash + neededMoney) && distance <= k){
                    price[dest] = cash + neededMoney;
                    q.push({dest, {distance + 1, price[dest]}});
                }
            }
        }
        if(price[dst] < INT_MAX) return price[dst];
        return -1;
    }
};