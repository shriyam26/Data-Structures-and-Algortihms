//Find minimum number of coins required to make up that amount.

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(amount == 0) return 0;
        vector<unsigned int> dp(amount + 1, INT_MAX);
        //cout << "dp.size(): " << dp.size() << endl;
        dp[0] = 0;
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j < dp.size(); j++){
                int rem = j - coins[i];
                /*
                cout << "i: " << i << " j: " << j << " rem: " << rem << endl;
                cout << "dp[j]: " << dp[j] << " dp[rem] + 1: " << dp[rem] + 1 << endl;
                for(int k = 0; k < dp.size(); k++){
                    cout << dp[k] << " ";
                }
                cout << endl;
                */
                dp[j] = min(dp[j], 1 + dp[rem]);
                /*
                cout << "New dp[j]: " << dp[j] << endl;
                for(int k = 0; k < dp.size(); k++){
                    cout << dp[k] << " ";
                }
                cout << endl << endl;
                */
            }
        }
        if(dp[amount] != INT_MAX)
            return dp[amount];
        return -1;
    }
};
//Time Complexity = O(Amount * coins.size())

//Find count of all possible combinations to make up that amount
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        int dp[amount + 1][n + 1];
        for(int i = 0; i <= amount; i++){
            for(int j = 0; j <= n; j++){
                dp[i][j] = 0;
            }
        }
        //We'll initialise all conditions with zero coins and any amount with 0
        for(int i = 0; i <= amount; i++){
            dp[i][0] = 0;
        }
        //We'll initialise all conditions with zero amount and any number of coins with 1
        for(int i = 0; i < n; i++){
            dp[0][i] = 1;
        }
        //Now we fill the table in bootom-up fashion, i.e we try t make each value from 1 to amount using given 
        //coins values and successively fill the number of ways to make each value from 1 to amount        
        for(int i = 0; i <= amount; i++){
            for(int j = 1; j <= n; j++){
                //if (j-1)th coin is less than amount i, then we have two choices, either to include (j-1)th coin or not.
                //If we include (j-1)th coin then check for remaining amount, else add the previous element value. We'll consider both conditions and then check //result.
                if(coins[j-1] <= i)
                    dp[i][j] += dp[i-coins[j-1]][j] + dp[i][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[amount][n];
    }
};

//Time Complexity = O(Amount * coins.size())