class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(begin(nums), end(nums));

        int c = st.size();

        int i = 0;
        int j = 0;
        int res = 0;

        unordered_map<int, int> mp;
        while(j < n) {
            mp[nums[j]]++;

            while(mp.size() == c) {
                res += (n-j);

                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }

            j++;
        }

        return res;
    }
};