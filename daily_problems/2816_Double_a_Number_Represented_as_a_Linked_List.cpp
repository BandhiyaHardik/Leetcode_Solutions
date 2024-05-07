class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        
        if(head->val >= 5) {
            ListNode* newHead = new ListNode(0);
            newHead->next = head;
            head = newHead;
        }
                
        ListNode* curr = head;
        
        while(curr != NULL) {
            
            curr->val = (curr->val * 2)%10;
                        
            if(curr->next != NULL && curr->next->val >= 5) {
                curr->val += 1;
            }
            
            curr = curr->next;
            
        }       
        
        return head;
    }
};