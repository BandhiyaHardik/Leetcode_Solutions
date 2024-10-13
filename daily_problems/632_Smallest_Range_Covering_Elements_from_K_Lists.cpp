class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

        int maxVal = INT_MIN;
        int start = 0, end = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
        }

        while (!minHeap.empty()) {
            auto curr = minHeap.top(); 
            minHeap.pop();
            int minVal = curr.first;
            int listIdx = curr.second.first;
            int elemIdx = curr.second.second;

            if (maxVal - minVal < end - start) {
                start = minVal;
                end = maxVal;
            }

            if (elemIdx + 1 < nums[listIdx].size()) {
                int nextVal = nums[listIdx][elemIdx + 1];
                minHeap.push({nextVal, {listIdx, elemIdx + 1}});
                maxVal = max(maxVal, nextVal);
            } else {
                break;
            }
        }

        return {start, end};
    }
};
