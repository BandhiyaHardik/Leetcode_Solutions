class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* prev = NULL;
        
        while(node && node->next) {
            node->val = node->next->val;
            prev = node;
            node = node->next;
        }
        delete(node);
        prev->next = NULL;
    }
};