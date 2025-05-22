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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode*o=head;
        ListNode*e=head->next;
        ListNode*ee=e;
        while(true){
            if(o==NULL || e==NULL || e->next==NULL){
                o->next=ee;
                break;
            }
            o->next=e->next;
            o=e->next;
            if(o->next==NULL){
                e->next=NULL;
                o->next=ee;
                break;
            }
            e->next=o->next;
            e=o->next;
        }
        return head;
    
    }
};