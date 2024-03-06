class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;  
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true; 
            }
        }

        return false;  
    }
};