
/*
For each day, if you don't have to travel today, then it's strictly better to wait to buy a pass. If you have to travel today, you have up to 3 choices: you must buy either a 1-day, 7-day, or 30-day pass.

We can express those choices as a recursion and use dynamic programming. Let's say dp(i) is the cost to fulfill your travel plan from day i to the end of the plan. Then, if you have to travel today, your cost is:

dp(i)=min(dp(i+1)+costs[0],dp(i+7)+costs[1],dp(i+30)+costs[2])
*/

class Solution {
public:
    set<int> dayset;
    int memo[366];
    int solve(int day, vector<int> &costs){
        if(day > 365) return 0;
        if(memo[day] != -1) return memo[day];
        int ans;
        if(dayset.find(day) != dayset.end()){
            ans = min(solve(day+1, costs) + costs[0], solve(day+7, costs) + costs[1]);
            ans = min(ans, solve(day+30, costs) + costs[2]);
        }
        else ans  = solve(day+1, costs);
        memo[day] = ans;
        return ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        for(int i = 0; i < 366; i++){
            memo[i] = -1;
        }
        for(int d : days) dayset.insert(d);
        return solve(1, costs);
    }
};