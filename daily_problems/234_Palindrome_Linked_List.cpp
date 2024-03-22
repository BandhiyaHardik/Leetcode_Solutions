class Solution {
public:
    ListNode* curr;

    bool solve(ListNode* head) {
        if(!head)
            return true;
        
        if(!solve(head->next) || head->val != curr->val) {
            return false;
        }

        curr = curr->next;
        return true;
    }

    bool isPalindrome(ListNode* head) {
        curr = head;

        return solve(head);
    }
};