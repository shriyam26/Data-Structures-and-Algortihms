/* k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is. */
class Solution {
public:
    int length(ListNode* head){
        if(!head) return 0;
        ListNode* curr = head;
        int count = 0;
        while(curr) {
            curr = curr->next;
            count++;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        int count  = 0;
        while(curr != nullptr &&  count < k){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        int len = length(next);
        //cout << "head->data " << head->val << " prev->data " << prev->val << endl;
        if(len >= k && next) head->next = reverseKGroup(next, k);
        else if(next) head->next = next;
        return prev;
    }
};