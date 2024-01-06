class Solution {
public:
    int binarySearch(const vector<vector<int>>& jobs, int end, int left, int right) {
        int result = -1; 

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (jobs[mid][1] <= end) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        int dp[n]; 
        vector<vector<int>> jobs(n, vector<int>(3));

        for(int i = 0; i < n; i++) { 
            jobs[i][0] = startTime[i]; 
            jobs[i][1] = endTime[i]; 
            jobs[i][2] = profit[i]; 
        }

        sort(jobs.begin(), jobs.end(), [](const vector<int>& m, const vector<int>& n) {
            return m[1] < n[1];
        });

        dp[0] = jobs[0][2];

        for (int i = 1; i < n; i++) {
            int prev = 0;

            int lastJobIndex = binarySearch(jobs, jobs[i][0], 0, i - 1);
            if (lastJobIndex != -1) {
                prev = dp[lastJobIndex];
            }

            dp[i] = max(prev + jobs[i][2], dp[i-1]);
        }
        
        return dp[n - 1];
    }
};
