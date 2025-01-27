class Solution {
public:

    bool dfs(unordered_map<int, vector<int>>& adj, int src, int dest, vector<bool>& visited) {
        visited[src] = true;

        if(src == dest) {
            return true;
        }

        bool isReacheable = false;
        for(auto &adjNode : adj[src]) {
            if(!visited[adjNode]) {
                isReacheable = isReacheable || dfs(adj, adjNode, dest, visited);
            }
        }

        return isReacheable;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for(auto &edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        int Q = queries.size();
        vector<bool> result(Q);

        for(int i = 0; i < Q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];

            vector<bool> visited(numCourses, false);
            result[i] = dfs(adj, u, v, visited);
        }

        return result;
    }
};
