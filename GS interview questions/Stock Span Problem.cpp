
/* Brute Force */
void calculateSpan(int price[], int n, int S[])
{
    // Span value of first day is always 1
    S[0] = 1;
 
    // Calculate span value of remaining days 
    // by linearly checking previous days
    for (int i = 1; i < n; i++)
    {
        S[i] = 1; // Initialize span value
 
        // Traverse left while the next element 
        // on left is smaller than price[i]
        for (int j = i - 1; (j >= 0) &&
                (price[i] >= price[j]); j--)
            S[i]++;
    }
}

/* O(N^2) & O(1) */


class Solution
{
    public:
    vector <int> calculateSpan(int price[], int n)
    {
        stack<int> st;
        vector<int> res(n);
        st.push(0);
        res[0] = 1;
        for(int i = 1; i < n; i++){
			// Pop elements from stack while stack is not
			// empty and top of stack is smaller than
			// price[i]
            while(!st.empty() && price[st.top()] <= price[i])
                st.pop();
				
			//if stack becomes empty, then price[i] is greater than all 
            //elements on left of it in list so span is i+1.
            //Else price[i] is greater than elements after value at top of stack.	
            res[i] = (st.empty()) ? (i + 1) : (i - st.top());
            st.push(i);
        }
        return res;
    }
};

/* O(N) & O(N) */


class StockSpanner {
public:
    stack<pair<int, int> > st;
    int k;
    StockSpanner() {
        //st.clear();
        k = -1;
    }
    
    int next(int price) {
        k++;
        if(k == 0) {
            st.push({0, price});
            return 1;
        }
        while(!st.empty() && st.top().second <= price)
            st.pop();
        int ret = (st.empty()) ? (k + 1) : (k - st.top().first);
        st.push({k, price});
        return ret;
    }
};