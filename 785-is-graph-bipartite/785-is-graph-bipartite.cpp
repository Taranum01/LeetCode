class Solution {
public:
    
    bool dfs(int src, vector<int>&visited, vector<vector<int>>&graph, int color){
        
        visited[src]=color;
        for(int child:graph[src]){
            
            if(visited[child]==-1){
                if(dfs(child,visited,graph, 1-color)==false)
                    return false;
            }
            else 
            {
                if(visited[child]==visited[src])
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int>visited(n,-1);
        
        for(int i=0; i<n; i++){
            if(visited[i]==-1){
                if(dfs(i,visited,graph,0)==false)
                    return false;
            }
        }
        return true;
    }
};