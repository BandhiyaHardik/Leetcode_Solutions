class Solution {
public:
    #define P pair<int, int>
    unordered_map<int, vector<P>> adj;

    int dijkstra(int n) {
        vector<int> result(n, INT_MAX);
        result[0] = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            int d    = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if (node == n - 1)
                return result[n - 1];
            
            if (d > result[node])
                continue;

            for (P &p : adj[node]) {
                int adjNode = p.first;
                int dist    = p.second;
                if (d + dist < result[adjNode]) {
                    result[adjNode] = d + dist;
                    pq.push({d + dist, adjNode});
                }
            }
        }
        return result[n - 1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> result;

        for (int i = 0; i < n - 1; ++i) {
            adj[i].push_back({i + 1, 1});
        }

        for (auto query : queries) {
            int u = query[0];
            int v = query[1];
            adj[u].push_back({v, 1});
            int d = dijkstra(n);
            result.push_back(d);
        }

        return result;
    }
};