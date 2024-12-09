class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> cumSum(n, 0);

        cumSum[0] = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i]%2 == nums[i-1]%2) { 
                cumSum[i] = cumSum[i-1]+1;
            } else {
                cumSum[i] = cumSum[i-1];
            }
        }

        vector<bool> result(m, false);
        int i = 0;
        for(vector<int>& query : queries) {
            int start = query[0];
            int end = query[1];

            if(cumSum[end] - cumSum[start] == 0) {
                result[i] = true;
            }
            i++;
        }

        return result;
    }
};