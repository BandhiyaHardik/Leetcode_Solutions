class Solution {
public:

    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, int> mp;

        for(int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            mp[val] = i;
        }

        int minIndex = INT_MAX;

        for(int row = 0; row < m; row++) {
            int lastIndex = INT_MIN;

            for(int col = 0; col < n; col++) {
                int val = mat[row][col];
                int idx = mp[val];
                lastIndex = max(lastIndex, idx);
            }

            minIndex = min(minIndex, lastIndex);
        }

        for(int col = 0; col < n; col++) {
            int lastIndex = INT_MIN;

            for(int row = 0; row < m; row++) {
                int val = mat[row][col];
                int idx = mp[val];
                lastIndex = max(lastIndex, idx);
            }

            minIndex = min(minIndex, lastIndex);
        }
        

        return minIndex;

    }
};
