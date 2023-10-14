class Solution {
public:

    int n;
    int dp[501][501];
    
    int solve(int idx, int remaining, vector<int>& cost, vector<int>& time) {
        
        if(remaining <= 0)
            return 0;
        
        if(idx == n) {
            return 1e9;
        }
        
        if(dp[idx][remaining] != -1) {
            return dp[idx][remaining];
        }
        
        int paint_i = cost[idx] + solve(idx+1, remaining - 1 - time[idx], cost, time);

        int not_paint_i = solve(idx+1, remaining, cost, time);
        
        return dp[idx][remaining] = min(paint_i, not_paint_i);
        
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {

        n = cost.size();
        
        memset(dp, -1, sizeof(dp));
        
        return solve(0, n, cost, time);
        
        
    }
};