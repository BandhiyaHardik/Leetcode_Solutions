class Solution {
public:
    int n;
    bool bfs(map<int, vector<int>>& mp, int start, int end) {
        vector<bool> visited(n+1, false);
        queue<int> que;
        que.push(start);
        
        while(!que.empty()) {
            int curr = que.front();
            que.pop();
            visited[curr] = true;
            if(curr == end)
                return true;
            
            for(int &x : mp[curr]) {
                if(!visited[x]) {
                    que.push(x);
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        map<int, vector<int>> mp;
        n = edges.size();
        
        for(int i = 0; i<n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            if(mp.find(u) != mp.end() && mp.find(v) != mp.end() && bfs(mp, u, v))
                return edges[i];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        return {};
    }
};