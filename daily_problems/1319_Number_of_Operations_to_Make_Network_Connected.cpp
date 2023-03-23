class Solution {
public:
   
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size()+1<n)return -1;
        vector<vector<int>>graph(n);
        for(auto x:connections){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        vector<bool>vis(n,false);
        int component=0;
  
        for(int i=0;i<n;i++){
            if(!vis[i]){
                queue<int>q;
                q.push(i);
                component++;
                while(!q.empty()){
                    int fnt=q.front();
                    q.pop();
                    for(auto x:graph[fnt]){
                        if(!vis[x]){
                            vis[x]=true;
                            q.push(x);
                        }
                    }
                }
            }
        }
        return component-1;
    }
    
};