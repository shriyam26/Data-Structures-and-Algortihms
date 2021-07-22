class Solution{
  public:
    //Function to insert a node at the beginning of the linked list.
    Node *insertAtBegining(Node *head, int x) {
       Node *temp = new Node(x);
       if(head==NULL)
       return temp;
       temp->next = head;
       return temp;
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node *insertAtEnd(Node *head, int x)  {
       Node *temp = new Node(x);
       if(head == NULL)
       return temp;
       else{
            Node *trav = head;
            while(trav->next != NULL){
                trav=trav->next;
        }
            trav->next = temp;
            temp->next = NULL;   
        }
        return head;
    }
	
};

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* createNode(int data){
    Node* temp = new Node();
    temp->data = data;
    temp->next = nullptr;
    return temp;
}

void insertAtStart(Node** head, int data){
    Node* temp = createNode(data);
    temp->next = *head;
    *head = temp;
}

void insertInBetween(Node* prev, int data){
    Node* temp = createNode(data);
    if(prev == nullptr)
    return;
    temp->next = prev->next;
    prev->next = temp;
}

void insertAtEnd(Node** head, int data){
    Node* temp = createNode(data);
    Node* curr = *head;
    if(*head == nullptr){
        *head = temp;
        return;
    }
    while(curr->next != nullptr){
        curr = curr->next;
    }
    curr->next = temp;
    temp->next = nullptr;
}

void printList(Node* node){
    while(node!=nullptr){
        cout<<"data: "<<node->data<<endl;
        node = node->next;
    }
}
int main(){
    Node* head = nullptr; 
    insertAtEnd(&head, 6); 
    insertAtStart(&head, 7); 
    insertAtStart(&head, 1); 
    insertAtEnd(&head, 4); 
    insertInBetween(head->next, 8); 
    cout<<"Created Linked list is: "; 
    printList(head); 
      
    return 0; 
}



Node* deleteNode(Node *head,int x)
{
    Node* temp = head;
    Node* prev = NULL;
    if(head == NULL) return NULL;
    if(x == 1) {
        head = temp->next;
        delete temp;
        return head;
    }
    int pos = 1;
    while(temp != NULL && pos < x){
        prev = temp;
        temp = temp->next;
        pos++;
    }
    prev->next = temp->next;
    delete temp;
    return head;
    
}

void deleteNode(Node** head, int key){
    Node* temp = *head;
    Node* prev = NULL;
    if(temp->data == key && temp != NULL){
        *head = temp->next;
        delete temp;
        return;
    }
    else{
        while(temp != NULL && temp->data != key){
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        delete temp;
    }
}

/* Leetcode Solution */

class Node{
public:
    int val;
    Node* next;
    Node(int x){
        val = x;
        next = nullptr;
    }
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    Node* head;
    int size;

    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index >= size || index < 0)
            return -1;
        Node* curr = head;
        int i = 0;
        while(i < index){
            curr = curr->next;
            i++;
        }
        //print();
        return curr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if(head == nullptr) {
            head = new Node(val);
            //print();
            size++;
            return;
        }
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        //print();
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(head == nullptr){
            head = new Node(val);
            size++;
            return;
        }
        Node* curr = head;
        Node* temp = new Node(val);
        while(curr->next)
            curr= curr->next;
        curr->next = temp;
        //print();
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size + 1 || index < 0)
            return;
        if(index == 0){
            addAtHead(val);
            return;
        }
        if(index == size + 1){
            addAtTail(val);
            return;
        }
        Node* curr = head;
        Node* temp = new Node(val);
        int i = 0;
        while(i < index - 1){
            curr = curr->next;
            i++;
        }
        //cout << "1 " << curr->val;
        temp->next = curr->next;
        curr->next = temp;
        //print();
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index >= size || index < 0)
            return;
        Node* curr = head;
        if(index == 0){
            Node* temp = head;
            head = curr->next;
            delete(temp);
        }
        else{
            int i = 0;
            while(i < index - 1){
                curr = curr->next;
                i++;
            }
            //print();
            Node* temp = curr->next;
            curr->next = temp->next;
            delete(temp);
            //print();
        }
        size--;
    }
    void print(){
        Node* curr = head;
        while(curr){
            cout << curr->val << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    ~MyLinkedList() {
        Node* temp = head;
        while(head){
            head = head->next;
            delete temp;
            temp = head;
        }
    }
    
};