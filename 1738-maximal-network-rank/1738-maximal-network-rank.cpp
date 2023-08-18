class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        unordered_map<int, unordered_set<int>> adj;
        
        for(auto &road : roads) {

            int u = road[0];
            int v = road[1];
            
            adj[u].insert(v);
            adj[v].insert(u);

        }
        
        int maxRank = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                
                int rank_i = adj[i].size();
                int rank_j = adj[j].size();
                
                int rank = rank_i + rank_j;
                
                if(adj[i].find(j) != adj[i].end()) {
                    
                    rank -= 1;
                }
                
                maxRank = max(maxRank, rank);
                
            }
        }
        
        return maxRank;
    }
};