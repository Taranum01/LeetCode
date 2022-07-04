
#define ll long long
int mod = 1e9+7;

class Solution {
public:
    
    int countHousePlacements(int n) {
        ll dp[n+1];
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i <= n; i++){
            dp[i] = (dp[i-1]+dp[i-2])%mod;
        }
        return (dp[n]*dp[n])%mod;
    }
};