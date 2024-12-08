class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {

        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<int> maxValues(n);
        maxValues[0] = events[0][2];

        for (int i = 1; i < n; ++i) {
            maxValues[i] = max(maxValues[i - 1], events[i][2]);
        }

        int result = 0;

        for (int i = 0; i < n; ++i) {
            int curValue = events[i][2];
            int startTime = events[i][0];

            int left = 0, right = i - 1, best = 0;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][1] < startTime) {
                    best = max(best, maxValues[mid]);
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            result = max(result, curValue + best);
        }

        return result;
    }
};
