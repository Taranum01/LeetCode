class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        
        vector<vector<int>>graph(n);
        
        for(int i=0; i<edges.size(); i++){
            
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
                
        }
        
        vector<bool>visited(n,false);
        set<int>s(restricted.begin(),restricted.end());
        int ans=1;
        dfs(0,graph,s,ans,visited);
        return ans;
    }
    
    void dfs(int node, vector<vector<int>> & graph, set<int>&s, int &ans, vector<bool>&visited ){
        
        visited[node]=true;
        for(int neighbour: graph[node])
        {
            if(s.find(neighbour)==s.end() && !visited[neighbour]){
                ans++;
            dfs(neighbour,graph,s,ans,visited);
            }
        }
    }
};