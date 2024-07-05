class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int firstCriticalIndex    = 0;
        int previousCriticalIndex = 0;

        int prevValue = 0;
        int currValue = 0;
        int nextValue = 0;

        int minDistance = INT_MAX;
        int index = 0;
        vector<int> result = {-1, -1};

        while (head != NULL) {
            prevValue = currValue;
            currValue = nextValue;
            nextValue = head->val;

            if (prevValue != 0 && currValue != 0 && nextValue != 0 && 
                (prevValue > currValue && currValue < nextValue ||
                prevValue < currValue && currValue > nextValue)) {
                
                if (firstCriticalIndex == 0) {
                    firstCriticalIndex = index;
                } else {
                    minDistance = min(minDistance, index - previousCriticalIndex);
                    result = {minDistance, index - firstCriticalIndex};
                }
                previousCriticalIndex = index;
            }

            index++;
            head = head->next;
        }

        return result;
    }
};