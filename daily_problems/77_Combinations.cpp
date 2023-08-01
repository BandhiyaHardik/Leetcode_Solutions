class Solution {
public:
    vector<vector<int>> result;
    
    void solve(int start, int n, int k, vector<int>& temp) {
        if(k == 0) {
            result.push_back(temp);
            return;
        }

        for(int i = start; i <= n; i++) {
            temp.push_back(i);
            solve(i+1, n, k-1, temp);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        
        solve(1, n, k, temp);
        
        return result;
    }
};