class Solution {
public:
    typedef long long ll;
    ll maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        vector<int> fayda;
        ll normalSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            fayda.push_back((nums[i] ^ k) - nums[i]);
            normalSum += 1ll * nums[i];
        }
        
        sort(fayda.begin(), fayda.end(), greater<int>());
        
        for (int i = 0; i < fayda.size()-1; i += 2) {

            ll pairSum = fayda[i] + fayda[i + 1];
            
            if (pairSum > 0) {
                normalSum += pairSum;
            }
        }
        return normalSum;
    }
};
