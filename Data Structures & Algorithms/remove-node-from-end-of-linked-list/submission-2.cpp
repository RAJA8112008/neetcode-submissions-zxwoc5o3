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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int totalnode=0;
        ListNode* temp=head;
        while(temp!=NULL){
            totalnode++;
            temp=temp->next;
        }
        int delnode=totalnode-n;
        if(delnode==0)return head->next;
        temp=head;
        int count=1;
        while(temp!=NULL && count<delnode){
            temp=temp->next;
            count++;
        }
        ListNode* del=temp->next;
        temp->next=del->next;
        delete(del);
        return head;
    }
};
