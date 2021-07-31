class Solution {
public:
    int binarySearch(int l, int r, vector<int> &nums, int target){
        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                l++;
            else
                r--;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        int ref = arr[0];
        if(n == 0) return -1;
        if(n == 1) return (nums[0] == target) ? 0 : -1;
        int pivot = -1;
        while(l <= r){
            if(l == n-1) break;
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[mid + 1]){
                pivot = mid;
                break;
            }
            else{
                if(nums[mid] >= ref) // means range [l...mid] is sorted.
                    l = mid + 1;
                else                 // means range [mid+1, r] is sorted
                    r = mid - 1;
            }
        }
        if(pivot == -1) return binarySearch(0, n-1, nums, target);
        if(target >= ref) return binarySearch(0, pivot, nums, target);
        return binarySearch(pivot + 1, n-1, nums, target);
    }
};