class Solution {
public:

    int mod = 1e9+7;

    int countOrders(int n) {
        

        if(n == 1) return 1;

        long long res = 1;

        for(int i=2; i<=n; i++){

            int spaces =  (i-1)*2 + 1;
            int possibility = spaces * (spaces+1) / 2;
            res *= possibility;
            res %= mod;

        }
        return res;
    }
};