class Solution {
public:
    int minCost(int n, vector<int>& cuts) {  
        
        int c = cuts.size();
        sort(cuts.begin(),cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        
        vector<vector<int>> dp(c+2,vector<int>(c+2,0));
        for(int i = c;i>=1;i--){
            for(int j = 1;j<=c;j++){
                if(i>j) continue;
                int mincost = INT_MAX;
                for(int ind = i;ind<=j;ind++){
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];   
                    if(cost<mincost) mincost = cost;
                }
                dp[i][j] = mincost;
            }
        }
        return dp[1][c];     
    }
};