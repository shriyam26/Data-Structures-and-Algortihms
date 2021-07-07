//https://www.youtube.com/watch?v=q6IEA26hvXc
//https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/1310317/solution-in-c%2B%2B-faster-than-95.30-20ms-no-need-to-visit-other-source-if-you-get-it

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
        for(int i = 0; i < nums2.size(); i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        int size = nums1.size();
        if(size % 2) return (double)nums1[size/2];
        return ((double)(nums1[size/2]) + (double)(nums1[(size/2) - 1]))/2;
        */
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n2 < n1)
            return findMedianSortedArrays(nums2, nums1);
        int total =  n1 + n2;
        int half =  total/2;
        int l = 0, r = n1-1; //we are assuming that 2nd array is smaller than 1st array.
        int Aleft, Bleft, Aright, Bright;
        while(true){
            int i = floor((l + r)/(2.0));
            int j = half - i - 2;
            if(i >= 0) Aleft = nums1[i];
            else Aleft = INT_MIN;
            if(j >= 0) Bleft = nums2[j];
            else Bleft = INT_MIN;
            if(i+1 < n1) Aright = nums1[i+1];
            else Aright = INT_MAX;
            if(j+1 < n2) Bright = nums2[j+1];
            else Bright = INT_MAX;
            if(Aleft <= Bright && Bleft <= Aright){
                if(total % 2) return (double)(min(Aright, Bright));
                return (double)(max(Aleft, Bleft) + min(Aright, Bright))/(2.0);
            }
            else if(Aleft > Bright){
                r = i - 1;
            }
            else 
                l = i + 1;
        }
    }
};