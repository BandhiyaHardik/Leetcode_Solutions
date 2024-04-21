class Solution {
public:    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> mp;
        
        for(vector<int> &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        
        queue<int> que;
        que.push(source);
        visited[source] = true;
        
        while(!que.empty()) {
            int node = que.front();
            que.pop();
            if(node == destination)
                return true;

            for(auto &it : mp[node]) {
                if(!visited[it]) {
                    visited[it] = true;
                    que.push(it);
                }
            }
        }
        
        return false;
    }
};