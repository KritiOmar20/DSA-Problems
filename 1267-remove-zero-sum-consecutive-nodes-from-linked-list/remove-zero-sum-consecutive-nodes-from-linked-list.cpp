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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp=new ListNode(0);
        temp->next=head;
        ListNode* curr=temp;
        while(curr!=nullptr) {
            ListNode* ptr=curr->next;
            int sum=0;
            while(ptr!=nullptr) {
                sum+= ptr->val;
                if(sum==0) {
                    curr->next=ptr->next;
                }
                ptr=ptr->next;
            }
            curr=curr->next;
        }
        return temp->next;
    }
};