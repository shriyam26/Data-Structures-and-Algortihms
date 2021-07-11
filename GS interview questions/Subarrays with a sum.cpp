/* Subarray with atmost K values */
 
    // Count of subarrays with exactly k distinct
    // elements is equal to the difference of the
    // count of subarrays with at most K distinct
    // elements and the count of subararys with
    // at most (K - 1) distinct elements
int atMostK(int arr[], int n, int k)
{
 
    // To store the result
    int count = 0;
 
    // Left boundary of window
    int left = 0;
 
    // Right boundary of window
    int right = 0;
 
    // Map to keep track of number of distinct
    // elements in the current window
    map<int,int> map;
    // Loop to calculate the count
    while (right < n) {
 
        // Calculating the frequency of each
        // element in the current window
        if (map.find(arr[right])==map.end())
            map[arr[right]]=0;
        map[arr[right]]++;
 
        // Shrinking the window from left if the
        // count of distinct elements exceeds K
        while (map.size() > k) {
            map[arr[left]]= map[arr[left]] - 1;
            if (map[arr[left]] == 0)
                map.erase(arr[left]);
            left++;
        }
 
        // Adding the count of subarrays with at most
        // K distinct elements in the current window
        count += right - left + 1;
        right++;
    }
    return count;
}
 
// Function to return the count of subarrays
// with exactly K distinct elements
int exactlyK(int arr[], int n, int k)
{
    return (atMostK(arr, n, k) - atMostK(arr, n, k - 1));
}

---------------------------------------------------------------------------

/*Subarrays with a given sum equal to k */
/*
We store the data in the form: (sum_i, no. of occurrences of sum_i). We traverse over the array numsnums and keep on finding the cumulative sum. Every time we encounter a new sum, we make a new entry in the hashmap corresponding to that sum. If the same sum occurs again, we increment the count corresponding to that sum in the hashmap. Further, for every sum encountered, we also determine the number of times the sum sum-ksum−k has occurred already, since it will determine the number of times a subarray with sum kk has occurred up to the current index. We increment the countcount by the same amount.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        mp.insert({0, 1});
        int currSum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            currSum += nums[i];
            if(mp.find(currSum-k) != mp.end()){
                count += mp[currSum-k];
            }
            mp[currSum]++;
        }
        return count;
    }
};