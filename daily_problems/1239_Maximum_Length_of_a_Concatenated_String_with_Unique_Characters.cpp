class Solution {
public:
      void dfs(int idx, int temp, int &result, vector<int>& uniqueCharStrings) {
          
            result = max(result, __builtin_popcount(temp));
          
            for (int i = idx; i < uniqueCharStrings.size(); i++) {
                
                if ((temp & uniqueCharStrings[i]) == 0) { 
                    
                    dfs(i + 1, temp | uniqueCharStrings[i], result, uniqueCharStrings);
                    
                }
            }
      }
    
      int maxLength(vector<string>& arr) {
        vector<int> uniqueCharStrings;

        for (string &s : arr) {
            unordered_set<char> st(begin(s), end(s));
            
            if (st.size() != s.length()) 
                continue;
            
            int val = 0; 
            for (char &ch : s) 
                val |= 1 << (ch - 'a');
            
            uniqueCharStrings.push_back(val);
        }

        int result = 0; 
        dfs(0, 0, result, uniqueCharStrings);
        return result;
    }
};