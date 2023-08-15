class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode* first = new ListNode();

        ListNode* curFirst = first;

        ListNode* second = new ListNode();

        ListNode* curSecond = second;
        
        while(head) {
            if(head->val < x) {
                curFirst->next = new ListNode(head->val);
                curFirst = curFirst->next;
            }
            else {
                curSecond->next = new ListNode(head->val);
                curSecond = curSecond->next;
            }
            head = head->next;
        }
        curFirst->next = second->next;
        return first->next;
    }
};