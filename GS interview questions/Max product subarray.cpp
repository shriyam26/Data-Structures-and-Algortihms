Finally, let's also consider negative numbers to find the general solution to the given problem. Consider the array 1, -2, -3, 4. 
When we are at the second element, our runningProduct becomes -2. But at the third element it becomes 6. So, as we encounter negative numbers they change the sign of our product. 
Our product can become really small but then really big depending on the sign of the current number. To accomodate for this, we can have two running products: maxProd and minProd. 
maxProd will track the maximum product that we can achieve and will reset whenever the current number is greater, just as above. minProd, on the other hand, will track the minimum product that we can achieve and will reset whenever the current number is smaller. 
Finally, whenever we encounter a negative number, we will swap maxProd and minProd because if a <= b then -b <= -a. This makes sure that maxProd and minProd are still the max and min products after multiplied by a negative number. And, with that, we have the following solution:

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Return early if input is empty
        if (nums.empty()) return 0;
		
        int best = INT_MIN;
        // Running products
        int maxProd = 1;
        int minProd = 1;
        
        for (int n: nums) {
            if (n < 0) {
                // Swap max and min
                swap(maxProd, minProd);
            }
            // Reset to current value if smaller or larger than it
            // (intuitively means that we start considering a new sub-array)
            maxProd = max(maxProd*n, n);
            minProd = min(minProd*n, n);
            // Update the best
            best = max(best, maxProd);
        }
        
        return best;
    }
};