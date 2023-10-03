class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> mp;
        
        for(int &num : nums) {
            result += mp[num]++;
        }
      
        return result;
    }
};