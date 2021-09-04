/*
Approach: The time complexity can be reduced by storing results of sub-problems. The idea is similar to this post.  

Maintain a boolean table[n][n] that is filled in bottom up manner.
The value of table[i][j] is true, if the substring is palindrome, otherwise false.
To calculate table[i][j], check the value of table[i+1][j-1], if the value is true and str[i] is same as str[j], then we make table[i][j] true.
Otherwise, the value of table[i][j] is made false.
We have to fill table previously for substring of length = 1 and length =2 because 
as we are finding , if table[i+1][j-1] is true or false , so in case of 
(i) length == 1 , lets say i=2 , j=2 and i+1,j-1 doesn’t lies between [i , j] 
(ii) length == 2 ,lets say i=2 , j=3 and i+1,j-1 again doesn’t lies between [i , j].
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res;
        int start;
        int maxlen = 1; //All substring of length 1 are palindromes
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        for(int i = 0; i < n; i++){ //Store values for string of length = 1
            dp[i][i] = true;
            start = i;
            maxlen = 1;
        }
        for(int i = 0; i < n - 1; i++){ //Check palindromes of length 2 in string
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                start = i;
                maxlen = 2;
            }
        }
        //Now check for all substrings from length = 3 to length = n
        for(int k = 3; k <= n; k++){
            for(int i = 0; i < n-k+1; i++){ //Fix starting index i.e. max from i = 0 to i = n-3
                int j = i + k - 1; //Fix end index
                if(s[i] == s[j] && dp[i+1][j-1]){ 
                    dp[i][j] = true;
                    start = i;
                    maxlen = max(maxlen, k);
                }
            }
        }
        return s.substr(start, maxlen);
    }
};