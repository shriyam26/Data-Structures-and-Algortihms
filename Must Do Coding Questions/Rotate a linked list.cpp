class Solution {
public:
    int length(ListNode* head){
        int count = 0;
        ListNode* curr = head;
        while(curr){
            curr = curr->next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int len = length(head);
        if(len == 0 || len == 1 || k == 0) return head;
        int pivot = k % len; //index from where rotation will occur
        if(pivot == 0) return head;
        ListNode* curr = head;
        ListNode* tail = head;
        int count = 0;
        while(tail->next){
            tail = tail->next;
        }
        tail->next = curr; //Joining last index to first
        tail = curr->next;
        while(count < (len - pivot) - 1){
            curr = curr->next;
            tail = tail->next;
            count++;
        }
        curr->next = NULL; //Breaking link between pivot index and index before that
        head = tail;
        return head;
    }
};