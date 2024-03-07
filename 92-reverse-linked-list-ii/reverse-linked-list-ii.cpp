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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode* rev= NULL;
        ListNode* revprev = NULL;
        ListNode* revend = NULL;
        ListNode* revnext= NULL;
        int i=1;
        ListNode* curr = head;
        while(curr and i<=right){
            if(i<left) revprev = curr;
            if(i==left) rev = curr;
            if(i==right) revend = curr;
            curr = curr->next;
            i++;
        }
        revnext = revend->next;
        revend->next = NULL;
        ListNode* newhead = reverse(rev);
        if(revprev != NULL) revprev->next = newhead;
        else head = newhead;
        rev->next = revnext;
        return head;
    }
};