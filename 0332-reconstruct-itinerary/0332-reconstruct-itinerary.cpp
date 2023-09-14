class Solution {
public:

    unordered_map<string, vector<string>> adj;

    vector<string> path;

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

        return path;

    }
    
    bool DFS(string fromAirport, vector<string>& temp) {

        temp.push_back(fromAirport);
      
        if (temp.size() == numTickets+1) {

            path = temp;
            return true;

        }
        
      
        vector<string>& neighbours = adj[fromAirport];
     
        for(int i = 0; i < neighbours.size(); i++) {
            
            string toAirport = neighbours[i];
            
            neighbours.erase(neighbours.begin()+i);
            
            if(DFS(toAirport, temp))
                return true;
       
            neighbours.insert(neighbours.begin()+i, toAirport);            
        }
        
        temp.pop_back();
        return false;
    }
};