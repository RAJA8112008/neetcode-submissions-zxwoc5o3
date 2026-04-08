/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* h1=list1;
        ListNode* h2=list2;
        ListNode* dummy=new ListNode(-1);
        ListNode* dummyhead=dummy;
        while(h1!=NULL && h2!=NULL){
            if(h1->val<=h2->val){
                dummyhead->next=new ListNode(h1->val);
                h1=h1->next;
            }else{
                dummyhead->next=new ListNode(h2->val);
                h2=h2->next;
            }
            dummyhead=dummyhead->next;
        }
        while(h1!=NULL){
            dummyhead->next=new ListNode(h1->val);
            h1=h1->next;
            dummyhead=dummyhead->next;
        }
        while(h2!=NULL){
            dummyhead->next=new ListNode(h2->val);
            h2=h2->next;
            dummyhead=dummyhead->next;
        }
        return dummy->next;
    }
};
