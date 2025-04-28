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
    ListNode* mergeNodes(ListNode* head) {
        if(head->val==0) head = head->next;
        ListNode* ans = head;
        ListNode* c= head;
        int sum = 0;
        while(c){
            if(c->val!=0){
                sum+=c->val;
                c= c->next;
            }
            else{
                ans->val=sum;
                ans->next=c->next;
                c=c->next;
                ans=c;
                sum=0;
            }
        }
        return head;
    }
};