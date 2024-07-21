class Solution {
public:

      vector<int> topoSort(vector<vector<int>>& edges, int n) {
        unordered_map<int, vector<int>> adj;
        stack<int> st;
        vector<int> order;
        vector<int> visited(n + 1, 0);
        bool hasCycle = false;

        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                dfs(i, adj, visited, st, hasCycle);
                if (hasCycle) 
                    return {};
            }
        }
        
        while(!st.empty()) {
            order.push_back(st.top());
            st.pop();
        }
        return order;
    }

    void dfs(int node, unordered_map<int, vector<int>>& adj, vector<int>& visited,
             stack<int>& st, bool& hasCycle) {
        
        visited[node] = 1;
        for (int& nbr : adj[node]) {
            if (visited[nbr] == 0) {
                dfs(nbr, adj, visited, st, hasCycle);
            } else if (visited[nbr] == 1) {
                hasCycle = true;
                return;
            }
        }

        visited[node] = 2;
        st.push(node);
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {        
        vector<int> orderRows    = topoSort(rowConditions, k);
        vector<int> orderColumns = topoSort(colConditions, k);

        if (orderRows.empty() or orderColumns.empty())
            return {};

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows[i] == orderColumns[j]) {
                    matrix[i][j] = orderRows[i];
                }
            }
        }
        return matrix;
    }
};