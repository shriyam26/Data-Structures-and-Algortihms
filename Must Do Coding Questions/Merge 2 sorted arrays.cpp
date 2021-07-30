class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    /*
        vector<int> res(m+n);
        int i = 0, j = 0, k = 0;
        while(i < m && j < n){
            if(nums1[i] <= nums2[j]) res[k++] = nums1[i++];
            else res[k++] = nums2[j++];
        }
        while(i < m){
            res[k++] = nums1[i++];
        }
        while(j < n){
            res[k++] = nums2[j++];
        }
        nums1 = res;
    */
        int p = m-1, q = n-1, curr = m + n - 1;
        for(int i = curr; i >= 0 && q >= 0; i--){
            if(p >= 0 && nums1[p] > nums2[q])
                nums1[i] = nums1[p--];
            else
                nums1[i] = nums2[q--];
        }
    }
    
};