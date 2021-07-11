class Solution {
public:
    int countNodes(long curr, long n) {
        long total = 0;
        long next = curr + 1;
        while(curr <= n){
            total += min(n - curr + 1, next - curr);
            next *= 10;
            curr *= 10;
        }
        return (int)total;
    }
    int findKthNumber(int n, int k) {
        long cur = 1;
        while (true) {
            if (k == 1) {
                return (int)cur;
            }
            int nodes = countNodes(cur, n); // Count nodes on the current level
            if (k <= nodes) { // This means we are on the correct subtree. Just go the lower
                cur *= 10;    // level
                k--;
            } 
            else {                 //This means result is on another subtree i.e (2-9).
                cur++;
                k -= nodes;
            }
        }
    }
    
};