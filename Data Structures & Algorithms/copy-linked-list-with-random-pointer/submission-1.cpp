/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
    //Dummy Linked List creation
    Node* dummy=new Node(head->val);
    Node* dummyhead=dummy;
    Node* temp=head->next;
    while(temp!=NULL){
        dummyhead->next=new Node(temp->val);
        dummyhead=dummyhead->next;
        temp=temp->next;
    }
   //to arrange the randome pointers
   unordered_map<Node*,Node*>mp;
   //store linked list to arrnage randome pointer
   temp=head;
   dummyhead=dummy;
   while(temp!=NULL){
    mp[temp]=dummyhead;
    temp=temp->next;
    dummyhead=dummyhead->next;
   }
   temp=head;
   dummyhead=dummy;
   //arrange the randome postringstream
   while(temp!=NULL){
    dummyhead->random=mp[temp->random];
    temp=temp->next;
    dummyhead=dummyhead->next;
   }
   return dummy;
    }
};
