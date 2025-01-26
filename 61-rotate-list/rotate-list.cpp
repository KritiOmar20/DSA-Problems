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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 or head == NULL) return head;
        ListNode *current = head;
        int ln =0;
        while(current->next!=NULL){
            ln += 1;
            current = current->next;
        }
        current->next = head;
        current = head;
        ln += 1;
        if(k>=ln){
            k=k%ln;
        }
        k = ln-k;
        for(int i=0;i<k-1;i++){
            current=current->next;
        }
        head = current->next;
        current->next = NULL;
        return head;

    }
};