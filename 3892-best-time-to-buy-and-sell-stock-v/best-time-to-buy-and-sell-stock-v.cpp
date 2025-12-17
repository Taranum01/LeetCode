class Solution {
public:

    long long dp[1001][501][3];

    long long solve(int i, int k, int CASE, vector<int>& prices) {

        if (i == prices.size()) {
            if (CASE == 0)
                return 0;
            return INT_MIN; 
        }

        if (dp[i][k][CASE] != INT_MIN)
            return dp[i][k][CASE];

        long long take = INT_MIN;
        long long dontTake;

        dontTake = solve(i + 1, k, CASE, prices);

        if (k > 0) {
            if (CASE == 1) {
                take = prices[i] + solve(i + 1, k - 1, 0, prices);
            }
            else if (CASE == 2) {
                take = -prices[i] + solve(i + 1, k - 1, 0, prices);
            }
            else {
                
                take = max(
                    -prices[i] + solve(i + 1, k, 1, prices), 
                     prices[i] + solve(i + 1, k, 2, prices)  
                );
            }
        }

        return dp[i][k][CASE] = max(take, dontTake);
    }

    long long maximumProfit(vector<int>& prices, int k) {

        int n = prices.size();

        for (int i = 0; i < n; i++)
            for (int j = 0; j <= k; j++)
                for (int l = 0; l < 3; l++)
                    dp[i][j][l] = INT_MIN;

        return solve(0, k, 0, prices);
    }
};