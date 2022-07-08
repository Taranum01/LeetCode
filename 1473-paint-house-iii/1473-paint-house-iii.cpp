class Solution {
public:
    
        int dp[105][25][105];
    
        int solve(vector<int>& houses, int i, int n, int m, vector<vector<int>>& cost, int target, int prev)
    {
        //end of array and target == neighbors
            
        if(i==n && target==0)
        {
            return 0;
        }
        
        //neighbors are greater than target
        
        if(i==n || target < 0)
            return INT_MAX;
        
        //already calculated
        
        if(prev != -1 && target != -1 && dp[i][prev][target] != -1)
            return dp[i][prev][target];
        
        int ans = INT_MAX;
        
        //houses[i] is already painted
        
        if(houses[i] != 0)
        {
            int temp_cost = 0;
            
            if(prev == houses[i])   // neighbors remain same
            {
                temp_cost = solve(houses, i + 1, n, m, cost, target, houses[i]);
            }
            else   // increase neighbors
            {
                temp_cost = solve(houses, i + 1, n, m, cost, target-1, houses[i]);
            }
            
            // update ans
            ans = min(ans, temp_cost);
        }
        
        else  // if houses[i] is not painted, try all colors
        {
            for(int j = 0; j < m; j++)
            {
                int temp_cost = 0;
                
                if(prev == j+1)   // neighbors remain same
                {
                    temp_cost = solve(houses, i + 1, n, m, cost, target, j + 1);
                }
                else    // increase neighbors
                {
                    temp_cost = solve(houses, i + 1, n, m, cost, target - 1, j + 1);
                }
                
                // update ans
                
                if(temp_cost != INT_MAX)
                {
                    ans = min(ans, cost[i][j] + temp_cost);
                }
            }
        }
        
        // store result
        
        if(prev != -1 && target != -1)
        {
            return dp[i][prev][target] = ans;
        }
        
        return ans;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int n, int m, int target) {
        
        memset(dp, -1, sizeof(dp));
        
        int ans = solve(houses, 0, n, m, cost, target, -1);
        
        return ans == INT_MAX ? -1 : ans;
    }
};