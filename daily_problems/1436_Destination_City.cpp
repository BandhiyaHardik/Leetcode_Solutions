class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;
        
        for(auto &path : paths) {
            string source = path[0]; 
            mp[source]++;
        }
        
        for(auto &path : paths) {
            string dest = path[1];
            
            if(mp[dest] == 0) {
                return dest;
            }
        }
        
        return "";
    }
};