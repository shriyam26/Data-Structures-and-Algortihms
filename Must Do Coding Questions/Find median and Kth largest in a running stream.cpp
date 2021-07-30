class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<double> maxHeap;
    priority_queue<double, vector<double>, greater<double> > minHeap;
    MedianFinder() {
        while(!maxHeap.empty()) maxHeap.pop();
        while(!minHeap.empty()) minHeap.pop();
    }
    
    void addNum(int num) {
        if(maxHeap.empty())       // If both are empty simply add to max Heap
            maxHeap.push(num);
        else{
            if(maxHeap.size() == minHeap.size()){    //if 'num' is smaller or equal to top of min_heap, simply add it to max_heap
                if(num <= minHeap.top())
                    maxHeap.push(num);
                else{
                    int top = minHeap.top();    //take top of min_heap, add this to max_heap, and add 'num' to min_heap
                    minHeap.pop();
                    maxHeap.push(top);
                    minHeap.push(num);
                }
            }
            else{
                if(num >= maxHeap.top())  // you can add 'num' to min_heap if 'num' >= max_heap.top()
                    minHeap.push(num);
                else{
                    int top = maxHeap.top();   //take top of max_heap, add it to min_heap, and add 'num' to max_heap
                    maxHeap.pop(); 
                    minHeap.push(top);
                    maxHeap.push(num);
                }
            }
        }
    }
    
    double findMedian() {
        if(minHeap.size() == maxHeap.size())
            return (maxHeap.top() + minHeap.top())/2.0;
        return maxHeap.top();
    }
};
/*
Time Complexity : O(N)
Space Complexity : O(N)

*/


class KthLargest {
public:
    priority_queue<int> pq;
    int n;
    int k1;
    KthLargest(int k, vector<int>& nums) {
        k1 = k;
        n = nums.size();
        for(int i = 0; i < n; i++) add(nums[i]);
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k1){
            pq.pop();
        }
        return pq.top();
    }
};
/*
Time Complexity : O(N)
Space Complexity : O(1)

*/
