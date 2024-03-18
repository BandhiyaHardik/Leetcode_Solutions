class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(begin(points), end(points));
        
        vector<vector<int>> balloons;
        balloons.push_back(points[0]);
        
        for(int i = 1; i<n; i++) {
            int currStartPoint = points[i][0];
            int currEndPoint   = points[i][1];
            
            int prevStartPoint = balloons.back()[0];
            int prevEndPoint   = balloons.back()[1];
            
            if(currStartPoint > prevEndPoint) {
                balloons.push_back(points[i]);
            } else {
                balloons.back()[0] = max(prevStartPoint, currStartPoint);
                balloons.back()[1] = min(prevEndPoint, currEndPoint);
            }
        }
        
        return balloons.size();
    }
};