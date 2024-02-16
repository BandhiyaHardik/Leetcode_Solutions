class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        
        for(int &x : arr) {
            mp[x]++;
        }

        vector<int> freq;
        
        for(auto &it : mp) {
            freq.push_back(it.second);
        }
        
        sort(begin(freq), end(freq));

        for(int i = 0; i < freq.size(); i++) {
            
            k -= freq[i];
            
            if(k < 0) {
                return freq.size() - i;
            }
        }
        
        return 0; 
    }
};