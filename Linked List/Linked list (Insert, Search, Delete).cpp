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