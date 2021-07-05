class Solution {
    int ans = INT_MIN;
    void dfs(vector<vector<int>>&grid,vector<vector<bool>>&visited,int i,int j,int row,int col,int sum)
    {
        if(i<0||j<0||i>=row||j>=col||visited[i][j]==true)return;
        visited[i][j] = true;
        sum += grid[i][j];
        ans = max(ans,sum);
        if(i+1<row && !visited[i+1][j] && grid[i+1][j] != 0)
            dfs(grid,visited,i+1,j,row,col,sum);
        if(i-1>=0 && !visited[i-1][j] && grid[i-1][j] != 0)
            dfs(grid,visited,i-1,j,row,col,sum);
        if(j+1<col && !visited[i][j+1] && grid[i][j+1] != 0)
            dfs(grid,visited,i,j+1,row,col,sum);
        if(j-1>=0 && !visited[i][j-1] && grid[i][j-1] != 0)
            dfs(grid,visited,i,j-1,row,col,sum);
         visited[i][j] = false;
        
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col,0));
       for(int i=0;i<row;i++)
       {
           for(int j=0;j<col;j++)
           {
               if(grid[i][j] != 0){
               //visited.clear();
               dfs(grid,visited,i,j,row,col,0);
               }
           }
       }
        return ans;
    }
};