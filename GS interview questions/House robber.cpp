/* DP Approach */

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n ; i++){
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]); //this step defines the two cases, if an element is selected then the previous element cannot be 		selected and if an element is not selected then the previous element can be selected
        }
        return dp[n-1];
    }
};


/* Without DP approach */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);
        int a = 0; 
        int b = 0;
        for(int i = 0; i < n ; i++){
            if(i % 2 == 0)
                a = max(a + nums[i], b);
            else
                b = max(a, nums[i] + b);
        }
        return max(a, b);
    }
};