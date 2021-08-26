class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) {
        int i, w;
        int dp[n+1][W+1];  //dp storing weights from 0 to W in column and value or weight array index from 0 to n in rows 
        for(i = 0; i <= n; i++){
            for(w = 0; w <= W; w++){
                if(i == 0 || w == 0)  // if i == 0, then there is no item to store in knapsack so equate dp to 0. Similarly if w == 0 then we are taking a bag of
                    dp[i][w] = 0;     // zero weight
                else if(wt[i-1] <= w)  //if weight of the item to store is less than or equal to weight of knapsack
                    dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][w - wt[i-1]]);  // take the max between previous row value and sum of value of that element & value of dp at element after subtracting the weight.
                else
                    dp[i][w] = dp[i-1][w]; // else take the value at previous row
            }
        }
        return dp[n][W];
    }
};