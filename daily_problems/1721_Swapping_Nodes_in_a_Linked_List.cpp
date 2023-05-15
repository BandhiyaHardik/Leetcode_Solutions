class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {

        ListNode* front = head;

        while(--k){
            front = front->next;
        }

        ListNode* ahead = front;
        ListNode* back = head;

        while(ahead->next){

            ahead = ahead->next;
            
            back = back->next;
        }
        swap(front->val,back->val);
        return head;
    }
};