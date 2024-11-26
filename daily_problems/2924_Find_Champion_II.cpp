class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            indegree[v]++;
        }

        int champ = -1;
        int count = 0;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                champ = i;
                count++;
                if(count > 1) {
                    return -1;
                }
            }
        }

        return champ;
    }
};