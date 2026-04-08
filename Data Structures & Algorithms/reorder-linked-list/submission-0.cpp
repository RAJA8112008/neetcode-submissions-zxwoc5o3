class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) return;

        ListNode* slow = head;
        ListNode* fast = head;

        // find middle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // separate into l1 and l2
        fast = head;
        while (fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL;

        // reverse second list
        ListNode* curr = slow;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* l1 = head;
        ListNode* l2 = prev;

        // merge in your style (using original nodes)
        while (l1 != NULL && l2 != NULL) {
            ListNode* next1 = l1->next;
            ListNode* next2 = l2->next;

            l1->next = l2;

            if (next1 == NULL) break;

            l2->next = next1;

            l1 = next1;
            l2 = next2;
        }
    }
};