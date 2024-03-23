class Solution {
public:
    ListNode* curr;
    
    void solve(ListNode* head) {
        if(!head) {
            return;
        }
        
        solve(head->next);
        ListNode* tempn = curr->next;
        if(tempn == NULL) {
            return;
        } else if(head == curr) {
            head->next = NULL;
            return;
        }
        
        curr->next = head;
        head->next = tempn == head ? NULL : tempn;
        
        curr = tempn;
    }
    
    void reorderList(ListNode* head) {
        curr = head;
        solve(head);
    }
};