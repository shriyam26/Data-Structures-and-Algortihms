class Solution {
public:
    int count(string s, int start, int end,int &result){
        while(start>=0 && end<s.length() && s[start] == s[end]){
            start--; end++; result++;
        }
        return result;
    }
    int countSubstrings(string s) {
        int result = 0;
        for(int i =0; i<s.length();i++){
            count(s,i,i,result);
            count(s,i,i+1,result);
        }
        return result;
    }
};