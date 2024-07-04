class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* P1 = head->next;
        ListNode* P2 = P1;

        while(P2 != NULL) {
            int sum = 0;
            while(P2 != NULL && P2->val != 0) {
                sum += P2->val;
                P2 = P2->next;
            }

            P1->val = sum;
            P2 = P2->next;
            P1->next = P2;
            P1 = P1->next;
        }

        return head->next;
    }
};