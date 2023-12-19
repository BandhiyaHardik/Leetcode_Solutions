class Solution {
public:
    vector<vector<int>> directions
    {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1}, {0, 0}, {0, 1},
        {1, -1}, {1, 0}, {1, 1}
    };
    
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> result(m, vector<int>(n));
        

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int sum = 0;
                int count = 0;
                
                for(auto &it : directions) {

                    int i_ = i + it[0];
                    int j_ = j + it[1];
                    
                    if (0 <= i_ && i_ < m && 0 <= j_ && j_ < n) {
                        sum += img[i_][j_];
                        count += 1;
                    }
                }

                result[i][j] = sum / count;
            }
        }
        
        return result;
        
    }
};