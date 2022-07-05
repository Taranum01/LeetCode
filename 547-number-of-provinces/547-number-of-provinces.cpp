class Solution {
public:
    
    void dfs(int src, int n, vector<vector<int>> &isConnected,  vector<bool>&visited ){
    visited[src]=true;
    
    vector<int>adj;
    for(int i=0; i<n; i++) {
        int x= isConnected[src][i];
        if(x==1)
            adj.push_back(i);
    }
    
    for(auto x:adj){
        if(!visited[x]){
            dfs(x, n, isConnected, visited);
        }
      }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        vector<bool>visited(n,false);
        int count=0;
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(i,n, isConnected, visited);
            }
        }
        
        return count;
    }
};