class Solution {
public:

    int n;
    int dp[501][501];
    int MOD = 1e9+7;

    int solve(int idx, int steps) {
        
        if(idx < 0 || idx >= n)
            return 0;
        
        if(steps == 0) {
            return idx == 0;
        }
        
        if(dp[idx][steps] != -1)
            return dp[idx][steps];
        
        int res = solve(idx+1, steps-1) % MOD; 

        res = (res + solve(idx-1, steps-1)) % MOD; 

        res = (res + solve(idx, steps-1)) % MOD; 
        
        return dp[idx][steps] = res;
        
    }
    
    int numWays(int steps, int arrLen) {
        
        arrLen = min(arrLen, steps/2+1);
        
        n = arrLen;

        memset(dp, -1, sizeof(dp));

        return solve(0, steps);
    }
};
