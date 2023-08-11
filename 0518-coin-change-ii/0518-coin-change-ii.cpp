class Solution {
public:

    int n;
    int dp[301][5001];
    
    int solve(int i, vector<int>& coins, int amount) {
        
        if(amount == 0)
            return dp[i][amount] = 1;
        
        if(i == n || amount < 0)
            return 0;
        
         if(dp[i][amount] != -1)
            return dp[i][amount];
        
        if(coins[i] > amount)
            return dp[i][amount] = solve(i+1, coins, amount);
        
        int take = solve(i, coins, amount-coins[i]);
        int skip = solve(i+1, coins, amount);
        
        return dp[i][amount] = take + skip;
        
    }
    
    int change(int amount, vector<int>& coins) {

        n = coins.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, coins, amount);
    }
};
