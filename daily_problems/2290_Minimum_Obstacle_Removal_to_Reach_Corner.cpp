class Solution {
public:
    #define P pair<int, pair<int, int>>
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> result(m, vector<int>(n, INT_MAX));

        result[0][0] = 0;

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int d = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            for(auto &dir : directions) {
                int x = i + dir[0];
                int y = j + dir[1];

                if(x < 0 || x >= m || y < 0 || y >= n) {
                    continue;
                }

                int wt = (grid[x][y] == 1) ? 1 : 0;

                if(d + wt < result[x][y]) {
                    result[x][y] = d + wt;
                    pq.push({d+wt, {x, y}});
                }
            }
        }

        return result[m-1][n-1];

    }
};