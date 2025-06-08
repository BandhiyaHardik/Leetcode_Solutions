class Solution {
public:

    void solve(int curr, int n, vector<int>& result) {
        if(curr > n)
            return;
        
        result.push_back(curr);

        for(int nextDigit = 0; nextDigit <= 9; nextDigit++) {
            int nextnum = curr*10 + nextDigit;
            
            if(nextnum > n)
                return;
            
            solve(nextnum, n, result);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> result;
        
        for(int num = 1; num <= 9; num++)
            solve(num, n, result);
        
        return result;
    }
};