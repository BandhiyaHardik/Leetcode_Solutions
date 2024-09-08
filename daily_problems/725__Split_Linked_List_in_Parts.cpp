class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr = head;
        int L = 0;
        while(curr) {
            L++;
            curr = curr->next;
        }
        
        int eachBucketNodes = L/k;
        int remainderNodes  = L%k;
        
        vector<ListNode*> result(k, NULL);
        curr           = head;
        ListNode* prev = NULL;
        
        for(int i = 0; curr && i < k ; i++) {
            
            result[i] = curr;
            
            for(int count = 1; count <= eachBucketNodes + (remainderNodes > 0 ? 1 : 0); count++) {
                prev = curr;
                curr = curr->next;
            }
            
            prev->next = NULL;
            remainderNodes--;
        }
        
        return result;
    }
};