////Function to return the minimum cost of connecting the ropes.

class Solution
{
    public:
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        for(long long i = 0; i < n; i++){
            pq.push(arr[i]);
        }
	    long long res = 0;
	    while(pq.size() > 1){
	        long long a = pq.top();
	        pq.pop();
	        long long b = pq.top();
	        pq.pop();
	        res += a + b;
	        pq.push(a + b);
	    }
	    return res;
    }
};

// Time Complexity:- O(nlogn)
// Space Complexity:- O(n)