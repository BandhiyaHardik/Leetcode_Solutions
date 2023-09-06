class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        if (!head) 
            return vector<ListNode*>(k, nullptr);

        ListNode* itr = head;
        int count = 0;
        while (itr) {
            count++;
            itr = itr->next;
        }
        
        int amount = count / k;
        int additional = count % k;        
        vector<ListNode*> output;
        ListNode* curr = head;
        ListNode* prev = nullptr;

        int next_start = amount + (additional > 0 ? 1 : 0);
        if (additional > 0) {
            additional--;
        }
        
        for (int i = 0; i < count; i++) {
            if (i == next_start) {
                prev->next = nullptr;
                output.push_back(curr);
                next_start += amount + (additional > 0 ? 1 : 0);
                if (additional > 0) {
                    additional--;
                }
            }
            prev = curr;
            curr = curr->next;
            if (i == 0) {
                output.push_back(head);
            }
        }
        
        while (output.size() < k) {
            output.push_back(nullptr);
        }
        
        return output;
    }
};