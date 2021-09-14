class Solution {
public:
	/*
	The idea is to use Hashing. Below is algorithm. 
	1. Traverse the original linked list and make a copy in terms of data. 
	2. Make a hash map of key value pair with original linked list node and copied linked list node. 
	3. Traverse the original linked list again and using the hash map adjust the next and random reference of cloned linked list nodes.
	*/
    Node* copyRandomList(Node* head) {
        Node *orgCurr = head;
        Node *cloneCurr = NULL;
        unordered_map<Node*, Node*> mp;
        while(orgCurr){
            int data = orgCurr->val;
            cloneCurr = new Node(data);
            mp[orgCurr] = cloneCurr;
            orgCurr = orgCurr->next;
        }
        orgCurr = head;
        while(orgCurr){
            cloneCurr = mp[orgCurr];
            cloneCurr->next = mp[orgCurr->next];
            cloneCurr->random = mp[orgCurr->random];
            orgCurr = orgCurr->next;
        }
        return mp[head];
    }
    // Time Complexity: O(n)
    // SpaceComplexity: O(n)
	
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node* orgCurr = head;
        Node* temp;
		//Create the copy of node 1 and insert it between node 1 & node 2 in the original Linked List, create a copy of 2 and insert it between 2 & 3. Continue in this fashion, add the copy of N after the Nth node
        while(orgCurr){
            temp = orgCurr->next;
            Node* cloneCurr = new Node(orgCurr->val);
            orgCurr->next = cloneCurr;
            cloneCurr->next = temp;
            orgCurr = temp;
        } 
        orgCurr = head;
		
		/*Now copy the random link in this fashion 
		original->next->random= original->random->next;  //TRAVERSE  TWO NODES
		This works because original->next is nothing but a copy of the original and Original->random->next is nothing but a copy of the random.*/
        while(orgCurr){
            if(orgCurr->random)
                orgCurr->next->random = orgCurr->random->next;
            orgCurr = orgCurr->next->next;
        }
        orgCurr = head; 
        Node* cloneCurr = head->next;
        temp = cloneCurr;
		
		/*Now restore the original and copy linked lists in this fashion in a single loop. 
		original->next = original->next->next;
		copy->next = copy->next->next; */
        while(orgCurr && cloneCurr){
            orgCurr->next = orgCurr->next->next;
            orgCurr = orgCurr->next;
            if(cloneCurr->next)
                cloneCurr->next = cloneCurr->next->next;
            cloneCurr = cloneCurr->next;
        }
        return temp;
    }
    // Time Complexity: O(n)
    // SpaceComplexity: O(1)
};