class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowRemainSum = accumulate(begin(grid[0]), end(grid[0]), 0LL);

        long long secondRowRemainSum = 0;

        long long minimizedRobot2Sum = LONG_LONG_MAX;

        for(int Robot1Col = 0; Robot1Col < grid[0].size(); Robot1Col++) {

            firstRowRemainSum -= grid[0][Robot1Col];

            long long bestOfRobot2 = max(firstRowRemainSum, secondRowRemainSum);

            minimizedRobot2Sum     = min(minimizedRobot2Sum, bestOfRobot2);

            secondRowRemainSum    += grid[1][Robot1Col];
        }

        return minimizedRobot2Sum;
    }
};
