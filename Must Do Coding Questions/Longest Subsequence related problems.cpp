/*Longest Common Subsequence Problem*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        int dp[m+1][n+1];
        int result = 0;
		//Traversing both the strings from lenth 0 to n and 0 to m
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
				//If length of any string is 0, save value as 0
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
				//If a character matches, then add the previous diagonal value to it and check the max value.	
                else if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
				//If no character matches, then set the adjacent max value.
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[m][n];
    }
	    //Time Complexity- O(N^2)
};

/*Longest Increasing Subsequence - Part 1*/

class Solution {
public:
    //Watch https://www.youtube.com/watch?v=1qD1FLhKrIE for clarification
    int lengthOfLIS(vector<int>& nums) {
        int n  = nums.size();
        vector<int> dp(n+1, INT_MAX);
        dp[0] = INT_MIN;
        for(int i = 0; i < n ; i++){
            //Find index in dp array which is just greater than nums[i]
            int index = upper_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            //Check here if index calculated is correct, if correct save nums[i] to dp[index]
            if(dp[index - 1] < nums[i] && dp[index] > nums[i])
                dp[index] = nums[i];
        }
		//The first index which is not equal to INT_MAX will give the length
        for(int i = n; i >= 0; i--){
            if(dp[i] != INT_MAX)
                return i;
        }
        return -1;
    }
    //Time Complexity- O(NlogN)
};


/*Longest Increasing Subsequence - Part 2*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n  = nums.size();
        vector<int> dp(n, 1);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    //Time Complexity- O(N^2)
};

/*Maximum Sum Increasing Subsequence*/
class Solution {
public:
    int maxSumOfLIS(vector<int>& nums) {
        int n  = nums.size();
        vector<int> dp(n, 1);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
			dp[i] += nums[i];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    //Time Complexity- O(N^2)
};