/*
Following are the two main steps to solve this problem: 
1) Calculate sum of the array. If sum is odd, there can not be two subsets with equal sum, so return false. 
2) If sum of array elements is even, calculate sum/2 and find a subset of array with sum equal to sum/2. 

First step is simple, the difficult thing is the 2nd part i.e. isSubsetPresent()
*/

/*
So we will create a 2D array of size (arr.size() + 1) * (target + 1) of type boolean. The state DP[i][j] will be true if there exists a subset of elements from A[0….i] with sum value = ‘j’. The approach for the problem is: 

if (A[i-1] > j)
DP[i][j] = DP[i-1][j]
else 
DP[i][j] = DP[i-1][j] OR DP[i-1][j-A[i-1]]
This means that if current element has value greater than ‘current sum value’ we will copy the answer for previous cases
And if the current sum value is greater than the ‘ith’ element we will see if any of previous states have already experienced the sum=’j’ OR any previous states experienced a value ‘j – A[i]’ which will solve our purpose.
*/
class Solution {
public:
    bool isSubsetPresent(vector<int>& nums, int target, int n){
        bool dp[n+1][target+1];
        for(int i = 0; i <= n; i++){
            dp[i][0] = true;
        }
        for(int j = 0; j <= target; j++){
            dp[0][j] = false;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= target; j++){
                if(j < nums[i-1])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][target];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        if(sum % 2 != 0)
            return false;
        return isSubsetPresent(nums, sum/2, n);
    }
};