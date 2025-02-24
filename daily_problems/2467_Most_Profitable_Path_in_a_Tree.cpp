class Solution {
public:
    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> bobMap;
    int aliceIncome;
    bool DFSBob(int curr, int t, vector<bool>&  visited) {
        visited[curr] = true;
        bobMap[curr] = t;

        if(curr == 0) {
            return true;
        }

        for(auto &ngbr : adj[curr]) {
            if(!visited[ngbr]) {
                if(DFSBob(ngbr, t+1, visited) == true) {
                    return true;
                }
            }
        }

        bobMap.erase(curr);
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();

        aliceIncome = INT_MIN;
        for(vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int time = 0;
        vector<bool> visited(n, false);
        DFSBob(bob, time, visited);
        
        int income = 0;
        visited.assign(n, false);

        queue<vector<int>> que;

        que.push({0, 0, 0});
        
        while(!que.empty()) {
            int curr = que.front()[0];
            int t = que.front()[1];
            int income = que.front()[2];

            que.pop();

            if(bobMap.find(curr) == bobMap.end() || bobMap[curr] > t) {
                income += amount[curr];
            } else if(t == bobMap[curr]) {
                income += (amount[curr])/2;
            }

            if(adj[curr].size() == 1 && curr != 0) {
                aliceIncome = max(aliceIncome, income);
            }

            for(int &ngbr : adj[curr]) {
                if(!visited[ngbr]) {
                    que.push({ngbr, t+1, income});
                }
            }

            visited[curr] = true;
        }

        return aliceIncome;
    }
};