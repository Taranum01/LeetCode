class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n=cost.size();
        int dp1=0;
        int dp2=0;
        
        for(int i=n-1; i>=0; i--){
            int dp= cost[i]+min(dp1,dp2);
            dp2=dp1;
            dp1=dp;
        }
        return min(dp1,dp2);
    }
};