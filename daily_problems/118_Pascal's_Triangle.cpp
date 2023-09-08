class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v;

        v.push_back({1});

        if(numRows == 1) {
            return v;
        }

        for (int i = 2; i <= numRows; i++) {

            vector<int> curr(i);

            curr[0] = 1;

            curr[i-1] = 1;

            for(int j = 1;j < v.back().size(); j++) {
                curr[j] = v.back()[j-1] + v.back()[j];
            }
            
            v.push_back(curr);
        }
        return v;
    }
};