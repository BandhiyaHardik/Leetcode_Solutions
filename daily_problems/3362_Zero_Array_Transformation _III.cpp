class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        priority_queue<int, vector<int>, greater<int>> past;

        priority_queue<int> maxHeap;

        sort(queries.begin(), queries.end());

        int j = 0;
        int usedCount = 0;

        for (int i = 0; i < n; ++i) {

            while (j < queries.size() && queries[j][0] == i) {
                maxHeap.push(queries[j][1]);
                ++j;
            }

            nums[i] -= past.size();

            while (nums[i] > 0 && !maxHeap.empty() && maxHeap.top() >= i) {
                int r = maxHeap.top(); maxHeap.pop();
                past.push(r);
                usedCount++;
                nums[i]--;
            }

            if (nums[i] > 0)
                return -1;

            while (!past.empty() && past.top() == i) {
                past.pop();
            }
        }

        return queries.size() - usedCount;
    }
};