class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> mp(n+1);
        
        vector<vector<int>> result;

        for(int &num : nums) {
            int freq = mp[num];
            
            if(freq == result.size()) {
                result.push_back({});
            }
            
            result[freq].push_back(num);
            mp[num]++;
        }
        
        return result;
        
    }
};