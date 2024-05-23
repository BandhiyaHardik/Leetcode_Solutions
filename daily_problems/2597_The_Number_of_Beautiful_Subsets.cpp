class Solution {
public:

    int result;
    int K;
    void dfs(vector<int> &nums, int idx, unordered_map<int, int> &mp) {

        if(idx == nums.size()) {
            result++;
            return;
        }

        dfs(nums, idx+1, mp);
        
        if(!mp[nums[idx] - K] && !mp[nums[idx] + K]) {
                mp[nums[idx]]++;
                dfs(nums, idx + 1, mp);
                mp[nums[idx]]--;
        }
    }

    int beautifulSubsets(vector<int>& nums, int k) {

        result = 0;
        K = k;

        unordered_map<int, int> mp;
 
        dfs(nums, 0, mp);

        return result - 1; 
    }
};