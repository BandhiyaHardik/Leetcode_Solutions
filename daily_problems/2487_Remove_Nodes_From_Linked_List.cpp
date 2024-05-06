class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* nextNode = removeNodes(head->next);

        if (head->val < nextNode->val) {
            delete head;
            return nextNode;
        }

        head->next = nextNode;
        return head;
    }
};
