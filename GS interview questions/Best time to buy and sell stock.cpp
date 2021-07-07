/* Best time to sell and buy stock once in a day */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = prices[0];
        int cost = 0;
        int maxCost = 0;
        for(int i = 1; i < prices.size(); i++){
            minVal = min(minVal, prices[i]);
            cost = prices[i] - minVal;
            maxCost = max(cost, maxCost);
        }
        return maxCost;
    }
};

/* Best time to sell and buy stock multiple times in a day */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Approach 2: Peak-Valley approach. Keep track of valleys and peaks on stock price
        int peak = 0;
        int valley = prices[0];
        int curr_profit = 0;
        int max_profit = 0 + curr_profit;
        for (int i = 1; i < prices.size(); i++) {

            // Update valley price
            if (valley > prices[i]) {
                valley = prices[i];
            }
            // Bottom reached and updating peak
            if (valley < prices[i] && peak < prices[i]) {
                peak = prices[i];
            }
            // Top reached, update max_profit and reset valley and peak
            if (valley < prices[i] && peak >= prices[i]) {
                // Compute and update profit
                curr_profit = peak - valley;
                max_profit += curr_profit;
                // cout << "VALLEY: " << valley;
                // cout << " PEAK: " << peak;
                // cout << " MAX PROFIT: " << max_profit << endl;
                // Reset valley and profit
                valley = prices[i];
                peak = 0;
            }
        }
        return max_profit;
		
		
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 1; i < prices.size() ; i++){
            int sub = prices[i] - prices[i-1];
            if(sub > 0)
                profit += sub;
        }
        return profit;
    }
};

/* Best time to sell and buy stock at most 2 times in a day */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0;
        vector<int> dpl(n), dpr(n);
        int lmin = prices[0];
        int cost;
        for(int i = 1; i < n; i++){
            lmin = min(lmin, prices[i]);
            cost = prices[i] - lmin;
            dpl[i] = max(dpl[i-1], cost);
        }
        int rmax = prices[n-1];
        for(int i = n-2; i >= 0; i--){
            rmax = max(rmax, prices[i]);
            cost = rmax - prices[i];
            dpr[i] = max(dpr[i+1], cost);
        }
        for(int i = 0; i < n; i++){
            res = max(res, dpl[i] + dpr[i]);
        }
        return res;
    }
};