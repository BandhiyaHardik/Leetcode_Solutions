class Solution {
public:
    int MOD = 1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        sort(begin(arr), end(arr));
        
        unordered_map<int, long long> mp;
        mp[arr[0]] = 1;
        
        for(int i = 1; i<n; i++) {
            
            long long count = 1;
            
            for(int j = 0; j < i; j++) {
                int v = arr[j];
                if(arr[i]%v == 0 && mp.find(arr[i]/v) != mp.end()) {
                    
                    count += (mp[v] * mp[arr[i]/v]);
                    
                }
                
            }
            
            mp[arr[i]] = count;
            
        }
        
        int result = 0;
        for(auto &it : mp){
            result = (result + it.second) % MOD;
        }
        return result;
    }
};
