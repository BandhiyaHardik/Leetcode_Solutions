class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int &x : nums) {
            mp[x]++;
        }

        for(auto &it : mp) {
            if(it.second % 2 != 0) {
                return false;
            }
        }

        return true;
    }
};