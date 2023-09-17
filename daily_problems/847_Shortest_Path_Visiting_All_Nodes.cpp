class Solution {
public:

    typedef pair<int, int> P;
    
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        
        if(n == 1 || n == 0)
            return 0;
        
        queue<P> que;
        
        set<P> vis;

        int allVisitedState = (1 << n) - 1; 
            
        for(int i = 0; i < n; i++) {
            int maskValue = (1 << i);
            
            que.push({i, maskValue});
            
            vis.insert({i, maskValue});
        }
        
        int result = 0;

        while(!que.empty())  {
            
            int N = que.size();
            result++;
            while(N--) {
                
                auto curr = que.front();
                que.pop();
                
                int currNode = curr.first;
                int currMask = curr.second;
                
                for(auto &adj: graph[currNode]) {
                    int nextMask = currMask | (1 << adj);
                    
                    if(nextMask == allVisitedState)
                        return result;
                    
                    if(vis.find({adj, nextMask}) == vis.end()) {
                        vis.insert({adj, nextMask});
                        que.push({adj, nextMask});                      
                    }
                }  
            }
        }

        return -1;
    }
};