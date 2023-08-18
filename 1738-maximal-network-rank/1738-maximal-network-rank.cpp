class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {

        vector<int> degree(n);
        vector<vector<bool>> connected(n, vector<bool>(n, false));
        
        for(auto &road : roads) {

            int u = road[0];
            int v = road[1];
            
            degree[u]++;
            degree[v]++;
            
            connected[u][v] = true;
            connected[v][u] = true;
        }
        
        int maxRank = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                
                int rank_i = degree[i];
                int rank_j = degree[j];
                
                int rank = rank_i + rank_j;
                
                if(connected[i][j] || connected[j][i]) {
                    rank -= 1;
                }
                
                maxRank = max(maxRank, rank);
                
            }
        }
        
        return maxRank;
    }
};
