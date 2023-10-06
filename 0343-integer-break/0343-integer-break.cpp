class Solution {
public:
    int integerBreak(int n) {
        
        vector<int>dp(60);

        dp[1]=1;
        dp[2]=1;
        dp[3]=2;

        for(int i=4; i<=n; i++){
            int num=i;
            for(int j=1; j<=num; j++){
                int a=j;
                int b=num-j;
                dp[i]= max({dp[i],a*b, dp[a]*b, dp[b]*a, dp[a]*dp[b]});
            }
        }
        return dp[n];
    }
};