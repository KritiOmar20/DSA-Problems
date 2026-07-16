class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        // Step 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Step 2: Reverse second half
        ListNode* second = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        while (second != NULL) {
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }
        // Step 3: Merge alternately
        ListNode* first = head;
        ListNode* sec = prev;
        while (sec != NULL) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = sec->next;
            first->next = sec;
            sec->next = temp1;
            first = temp1;
            sec = temp2;
        }
    }
};