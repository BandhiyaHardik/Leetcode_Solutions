class Solution {
public:
    int findTreeDiameter(const vector<vector<int>>& edges, int nodes) {
        vector<vector<int>> adj(nodes);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        auto bfs = [&](int start) {
            vector<int> dist(nodes, -1);
            queue<int> q;
            q.push(start);
            dist[start] = 0;
            int farthestNode = start, maxDist = 0;
            
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int neighbor : adj[curr]) {
                    if (dist[neighbor] == -1) {
                        dist[neighbor] = dist[curr] + 1;
                        q.push(neighbor);
                        if (dist[neighbor] > maxDist) {
                            maxDist = dist[neighbor];
                            farthestNode = neighbor;
                        }
                    }
                }
            }
            return make_pair(farthestNode, maxDist);
        };

        auto [farthestNode, _] = bfs(0);
        auto [_, diameter] = bfs(farthestNode);
        return diameter;
    }
    
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1, n2 = edges2.size() + 1;
        
        int diameter1 = findTreeDiameter(edges1, n1);
        int diameter2 = findTreeDiameter(edges2, n2);
        
        int radius1 = (diameter1 + 1) / 2;
        int radius2 = (diameter2 + 1) / 2;
        return max({diameter1, diameter2, radius1 + radius2 + 1});
    }
};
