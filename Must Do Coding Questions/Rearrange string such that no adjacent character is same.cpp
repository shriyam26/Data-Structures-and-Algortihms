class Solution {
public:
    string reorganizeString(string s) {
        int count[26] = {0};
        int max = 0;
        int n = s.length();
        string ans (n, ' ');
        //First we will calculate frequency of each character and save the element with max frequency in max variable.
        for(int i = 0; i < s.length(); i++){
            count[s[i] - 'a']++;
            if(count[s[i] - 'a'] > count[max])
                max = s[i] - 'a';
        }
        // if frequency of max occuring variable is greater than half of array length, then not possible.
        if(count[max] > (n+1)/2)
            return "";
        int j = 0;
        // First place all occurences of maximum count element at even positions.
        while(count[max] != 0){
            ans[j] = max + 'a';
            j = j + 2;
            count[max]--;
        }
        // Then place all remaining occurences of element, First check if j is less than n, then keep adding at even position otherwise start from 1.
        for(int i = 0; i < 26; i++){
            while(count[i] > 0){
                if(j >= n)
                    j = 1;
                ans[j] = i + 'a';
                j += 2;
                count[i]--;
            }
        }
        return ans;
    }
};

Time Complexity : O(N)
Space Complexity: O(N+26)