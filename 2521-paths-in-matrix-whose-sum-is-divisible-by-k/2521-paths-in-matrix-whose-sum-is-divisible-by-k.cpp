class Solution {
public:

    long long mod = 1e9 + 7;

    int solve(vector<vector<int>>&grid, int i, int j, int n, int m, int sum, int k, vector<vector<vector<int>>>&dp){

        sum += grid[i][j];

        if(i == n-1 && j == m-1){

            if(sum%k == 0){
                return 1;
            }
            else{
                return 0;
            }
        }

        if(dp[i][j][sum%k] != -1){
            return dp[i][j][sum%k];
        }

        int count = 0;

        if(i+1 < n){
            count = (count % mod + solve(grid, i+1, j, n, m, sum, k, dp)%mod)%mod;
        }

        if(j+1 < m){
            count = (count % mod + solve(grid, i, j+1, n, m, sum, k, dp) % mod) %mod;
        }
        
        return dp[i][j][sum%k] = count;
    }


    int numberOfPaths(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(m+1, vector<int>(k+1, -1)));

        return solve(grid, 0, 0, n, m, 0, k, dp);
    }
};