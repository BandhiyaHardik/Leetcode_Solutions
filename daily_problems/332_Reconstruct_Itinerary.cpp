class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<string> route;
    int numTickets = 0;
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
		numTickets = tickets.size();
        
		for (auto& t : tickets) {
            string u = t[0];
            string v = t[1];
            
			adj[u].push_back(v);
		}

        for (auto &edges : adj) {
            sort(begin(edges.second), end(edges.second));
        }
        
        vector<string> temp;
        DFS("JFK", temp);
        return route;
    }
    
    bool DFS(string fromAirport, vector<string>& temp) {
        temp.push_back(fromAirport);

        if (temp.size() == numTickets+1) {
            route = temp;
            return true;
        }
            
        vector<string>& neighbors = adj[fromAirport];
        
        for(int i = 0; i < neighbors.size(); i++) {
            
            string toAirport = neighbors[i];

            neighbors.erase(neighbors.begin()+i);
            
            if(DFS(toAirport, temp))
                return true;
            
            neighbors.insert(neighbors.begin()+i, toAirport);            
        }
        
        temp.pop_back();
        return false;
    }
};