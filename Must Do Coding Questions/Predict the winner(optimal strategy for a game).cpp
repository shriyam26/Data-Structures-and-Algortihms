/*
We can observe that the effective score for the current player for any given subarray nums[x:y]nums[x:y] only depends on the elements within the range [x,y][x,y] in the array numsnums. It mainly depends on whether the element nums[x]nums[x] or nums[y]nums[y] is chosen in the current turn and also on the maximum score possible for the other player from the remaining subarray left after choosing the current element. Thus, it is certain that the current effective score isn't dependent on the elements outside the range [x,y][x,y].

Based on the above observation, we can say that if know the maximum effective score possible for the subarray nums[x+1,y]nums[x+1,y] and nums[x,y-1]nums[x,y−1], we can easily determine the maximum effective score possible for the subarray nums[x,y]nums[x,y] as \text{max}(nums[x]-score_{[x+1,y]}, nums[y]-score_{[x,y-1]})max(nums[x]−score 
[x+1,y]
​
 ,nums[y]−score 
[x,y−1]
​
 ). These equations are deduced based on the last approach.

From this, we conclude that we can make use of Dynamic Programming to determine the required maximum effective score for the array numsnums. We can make use of a 2-D dpdp array, such that dp[i][j]dp[i][j] is used to store the maximum effective score possible for the subarray nums[i,j]nums[i,j]. The dpdp updation equation becomes:

dp[i,j] = nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]dp[i,j]=nums[i]−dp[i+1][j],nums[j]−dp[i][j−1].

We can fill in the dpdp array starting from the last row. At the end, the value for dp[0][n-1]dp[0][n−1] gives the required result. Here, nn refers to the length of numsnums array.
*/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1][n+1];
        for(int start = n; start >= 0; start--){
            for(int end = start; end < n; end++){
                if(start == end){
                    dp[start][end] = nums[start];
                }
                else{
                    int a = nums[start] - dp[start + 1][end];
                    int b = nums[end] - dp[start][end - 1];
                    dp[start][end] = max(a, b);
                }
            }
        }
        return dp[0][n-1] >= 0;
    }
};
//Time Complexity - O(N^2)
// Space Complexity - O(N^2)

/*
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int dp[n+1];
        for(int start = n; start >= 0; start--){
            for(int end = start; end < n; end++){
                if(start == end){
                    dp[start] = nums[start];
                }
                else{
                    int a = nums[start] - dp[end];
                    int b = nums[end] - dp[end - 1];
                    dp[end] = max(a, b);
                }
            }
        }
        return dp[n-1] >= 0;
    }
};
*/

//Time Complexity - O(N^2)
// Space Complexity - O(N)