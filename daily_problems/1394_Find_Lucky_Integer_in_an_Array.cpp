class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        for(int &x : arr) {
            mp[x]++;
        }
        
        int ans = -1;
        for(auto &it : mp) {
            if(it.first == it.second)
                ans = max(ans, it.first);
        }
        
        return ans;
    }
};