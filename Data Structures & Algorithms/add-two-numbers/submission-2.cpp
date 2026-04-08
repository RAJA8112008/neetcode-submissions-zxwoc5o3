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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1=l1;
        ListNode* h2=l2;
        int sum=0;
        int carry=0;
        ListNode* dummy=new ListNode(-1);
        ListNode* dummyhead=dummy;
        while(h1!=NULL || h2!=NULL || carry){
            sum=carry;
            if(h1){
                sum+=h1->val;
                h1=h1->next;
            }
            if(h2){
                sum+=h2->val;
                h2=h2->next;
            }
            dummyhead->next=new ListNode(sum%10);
            dummyhead=dummyhead->next;
            carry=sum/10;
        }
   return dummy->next;
    }
};
