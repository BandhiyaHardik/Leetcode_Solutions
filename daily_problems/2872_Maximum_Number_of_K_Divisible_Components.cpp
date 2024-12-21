class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int components = 0;
        
        function<int(int, int)> dfs = [&](int node, int parent) {
            int sum = values[node] % k;
            for (int neighbor : adj[node]) {
                if (neighbor != parent) {
                    sum += dfs(neighbor, node);
                    sum %= k;
                }
            }
            if (sum == 0) components++;
            return sum;
        };
        
        dfs(0, -1);
        return components;
    }
};
