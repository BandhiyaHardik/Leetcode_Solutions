class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        sort(begin(points), end(points));
        
        int maxVal = 0;
        
        for(int i = 1; i<n; i++) {
            maxVal = max(maxVal, points[i][0] - points[i-1][0]);
        }
        
        return maxVal;
        
    }
};