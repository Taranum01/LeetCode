class Solution {
public:
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        vector<vector<int>>dp(matrix.size(), vector<int>(matrix[0].size(),0));
        
        int Max=0;
        
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++){
                
                Max= max(Max,lip(matrix,i,j, dp));
                
            }
        }
        return Max;
    }
    
    int lip(vector<vector<int>>&matrix, int i, int j, vector<vector<int>>&dp) {
        
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size())
        return 0;
        
        if(dp[i][j]>0) return dp[i][j];
        
        int currMax=1;

        if(i+1<matrix.size() && i+1>=0 && matrix[i+1][j]>matrix[i][j]){
            
            currMax= max(currMax, 1+lip(matrix,i+1, j, dp));
        }
        
        if(j+1<matrix[0].size() && j+1>=0 && matrix[i][j+1]>matrix[i][j]){
            
            currMax= max(currMax, 1+lip(matrix,i, j+1, dp));
        }
        
        if(j-1<matrix[0].size() && j-1>=0 && matrix[i][j-1]>matrix[i][j]){
            
            currMax= max(currMax, 1+lip(matrix,i, j-1, dp));
        }
        
        if(i-1<matrix.size() && i-1>=0 && matrix[i-1][j]>matrix[i][j]){
            
            currMax= max(currMax, 1+lip(matrix,i-1, j, dp));
        }
        
        dp[i][j]=currMax;
        
        return currMax;
    }
};