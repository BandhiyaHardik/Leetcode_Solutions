class Solution {
public:

    int dfs(int box, vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, unordered_set<int>& visited, unordered_set<int>& foundBoxes) {
        
        if(visited.count(box)) {
            return 0;
        }

        if(status[box] == 0) {
            foundBoxes.insert(box);
            return 0;
        }

        visited.insert(box);
        int candiesCollected = candies[box];


        for(int &insideBox : containedBoxes[box]) {
            candiesCollected += dfs(insideBox, status, candies, keys, containedBoxes, visited, foundBoxes);
        }

        for(int &boxKey : keys[box]) {
            status[boxKey] = 1;
            if(foundBoxes.count(boxKey)) {
                candiesCollected += dfs(boxKey, status, candies, keys, containedBoxes, visited, foundBoxes);
            }
        }

        return candiesCollected;

    }

    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int candiesCollected = 0;
        unordered_set<int> visited;
        unordered_set<int> foundBoxes;

        for(int &box : initialBoxes) {
            candiesCollected += dfs(box, status, candies, keys, containedBoxes, visited, foundBoxes);
        }

        return candiesCollected;
    }
};