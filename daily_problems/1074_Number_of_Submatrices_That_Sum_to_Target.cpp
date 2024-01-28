class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(); 
        int cols = matrix[0].size(); 

        for(int row = 0; row<rows; row++) {
            for(int col = 1; col<cols; col++) {
                matrix[row][col] += matrix[row][col-1];
            }
        }

        int result = 0;
        for(int startCol = 0; startCol<cols; startCol++) {
            
            for(int currCol = startCol; currCol<cols; currCol++) {

                unordered_map<int, int> mp;
                mp[0] = 1;
                int sum = 0;
                for(int row = 0; row<rows; row++) {
                    sum += matrix[row][currCol] - (startCol > 0 ? matrix[row][startCol-1] : 0);
                    
                    if(mp.count(sum-target)) {
                        result += mp[sum-target];
                    }
                    
                    mp[sum]++;
                    
                }
                
            }
        }
        
        return result;
    }
};
