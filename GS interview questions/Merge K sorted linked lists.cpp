class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        ListNode* temp = nullptr;
        for(int i = 0; i < lists.size(); i++){
            temp = lists[i];
            while(temp){
                arr.push_back(temp->val); // push all elements of list in vector
                temp = temp->next;
            }
        }
        sort(arr.begin(), arr.end()); // sort all elements and then push these sorted elements in a linked list
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        for(int i = 0; i < arr.size(); i++){
            if(!head){
                head = new ListNode(arr[i]);
                tail = head;
            }
            else{
                tail->next = new ListNode(arr[i]);
                tail = tail->next;
            }
        }
        return head;
    }
};

/*
Time Complexity: O(N * log k) or O(n * k * log k), where, ‘N’ is the total number of elements among all the linked lists, ‘k’ is the total number of lists, and ‘n’ is the size of each linked list.
*/

----------------------------------------------------

/* Priority Queue */
class Solution {
    class compare{
        public:
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]) 
                pq.push(lists[i]);
        }
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        ListNode* temp = nullptr;
        while(!pq.empty()){
            temp = pq.top();
            pq.pop();
            tail->next = temp;
            tail = tail->next;
            if(temp->next) 
                pq.push(temp->next);
        }
        return head->next;
    }
};

/*
Time Complexity: O(N * log k) or O(n * k * log k), where, ‘N’ is the total number of elements among all the linked lists, ‘k’ is the total number of lists, and ‘n’ is the size of each linked list.
Insertion and deletion operation will be performed in min-heap for all N nodes.
Insertion and deletion in a min-heap require log k time.
Auxiliary Space: O(k). 
The priority queue will have atmost ‘k’ number of elements at any point of time, hence the additional space required for our algorithm is O(k).
*?