class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
		// We'll basically traverse both the linked list if any of the linked list comes to an end we'll make it point to head of another linked list.
		// Then once both these linked list have changes their heads, they would have traversed distance such that both pointers would be at same distance from
		// intersection point. if they become equal return the node
        while(curr1 != curr2){
            curr1 = curr1->next;
            curr2 = curr2->next;
            if(curr1 == curr2)
                return curr1;
            if(!curr1)
                curr1 = headB;
            if(!curr2)
                curr2 = headA;
        }
        return curr1;
    }
};