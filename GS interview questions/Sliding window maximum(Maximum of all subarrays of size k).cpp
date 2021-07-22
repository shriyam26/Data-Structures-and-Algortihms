class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        priority_queue<pair<int, int> > pq;
        for(int i = 0; i < k ; i++){
            pq.push({nums[i], i});
        }
        res.push_back(pq.top().first);
        for(int i = k; i < n; i++){
            pq.push({nums[i], i});
            while(pq.top().second < i-k+1) //If element is not in the range of [i - k + 1, i]
                pq.pop();
            res.push_back(pq.top().first);
        }
        return res;
    }
};


/*2nd method*/

int max = INT_MIN;
    if(k == 1) return nums;
    vector<int> maxSlidingWindow;
    for(int i = 0; i < k; i++){
        if(max < nums[i])
            max = nums[i];
    }
    maxSlidingWindow.push_back(max);
    for(int i = k; i < nums.size(); i++){
        int ind = i-k+1;
        for(int j = ind; j < ind+k; j++){
            if(max < nums[j])
				max = nums[j];
        }
        maxSlidingWindow.push_back(max);
            
    }
    return maxSlidingWindow;