#include<iostream>
using namespace std;
int max(int a, int b){
    return a > b ? a : b;
}

int maxPath(int grid[][5], int n, int m) {
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0&&j==0)
                continue;
            else if(i==0)
                grid[i][j]+=grid[i][j-1];
            else if(j==0)
                grid[i][j]+=grid[i-1][j];
            else
                grid[i][j]+=max(grid[i-1][j],grid[i][j-1]);
        }
    }
    return grid[n-1][m-1];
}

/*
Dp Solution =>

int MaximumPathUtil(int i, int j, vector<vector<int> >& grid)
{
    // Base condition
      if (i == 0 || j == 0)
        return 0;
 
      // If current subproblem is already computed,
      // we simply return its result from the dp table
      if (dp[i][j] != -1)
        return dp[i][j];
 
      // Computing the current subproblem and
      // store the result in the dp table for future use
      return dp[i][j] = max(MaximumPathUtil(i, j-1, grid), MaximumPathUtil(i - 1, j, grid)) +
                        grid[i-1][j-1];
}
 
int MaximumPath(vector<vector<int> >& grid)
{
    // Dimensions of grid[][]
    int n = grid.size();
    int m = grid[0].size();
 
      // dp table to memoize the subproblem results
      dp.resize(n+1, vector<int> (m+1, -1));
 
      // dp[n][m] gives the max. path sum
      // from grid[0][0] to grid[n-1][m-1]
      return MaximumPathUtil(n, m, grid);
}
*/

int main()
{
    int a[5][5]={{3, 7, 9, 2, 7},
                 {9, 8, 3, 5, 5},
                 {1, 7, 9, 8, 6},
                 {3, 8, 6, 4, 9},
                 {6, 3, 9, 7, 8}};
    cout<<maxPath(a,5,5)<<endl;
}