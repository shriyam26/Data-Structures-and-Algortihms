/*
In this solution, we will start comparing values from right. We will search for point where a[i-1] > a[i] i.e if the array is decreasing order then there can't be any greater permutation. We have to search for a point where the order changes. When a[i-1] >  a[i] is out point. Now then we'll get i-1 as our index point. Now we'll search for an element value which is just greater than a[i-1]. We start the search by comparing with a[j] from right side. After getting the element just greater than a[i-1], we'll swap both a[i-1] and a[j]. Then' we'll just reverse the elements after a[i-1] to get the greater permutation. Since all the elements to the right of a[i-1] were already sorted in decreasing order, that's why we reverse them.
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        int i = n -2, j = n - 1;
        while(i >= 0 && nums[i] >= nums[i+1]){
            i--;
        }
        if(i >= 0){
            while(nums[i] >= nums[j]){
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};