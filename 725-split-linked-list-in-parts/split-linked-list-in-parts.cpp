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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result(k, nullptr);
        int total = 0;
        ListNode* curr = head;
        while (curr) {
            total++;
            curr = curr->next;
        }

        int baseSize = total / k;
        int extra = total % k;

        curr = head;
        for (int i = 0; i < k; ++i) {
            ListNode* part = curr;
            int partSize = baseSize + (i < extra ? 1 : 0);

            for (int j = 0; j < partSize - 1 && curr; ++j) {
                curr = curr->next;
            }

            if (curr) {
                ListNode* nextPart = curr->next;
                curr->next = nullptr;
                curr = nextPart;
            }
            result[i] = part;
        }
        return result;
    }
};