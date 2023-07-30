class Solution {
public:

    int n;
    vector<vector<int>> dp;
    
    int solve(int l, int r, string& s){

        if(l == r)
            return 1;
        
        else if(l > r)
            return 0;
        
        if(dp[l][r] != -1)
            return dp[l][r];


        int i = l+1;
        while(i <= r && s[i] == s[l])
            i++;

        if(i == r+1)
            return 1;

        int first = 1 + solve(i,r,s);

        int second = INT_MAX;

        for(int j = i; j <= r; j++){
            if(s[l] == s[j]){
                
                int x = solve(i,j-1,s) + solve(j,r,s);
                
                second = min(second, x);
            }
        }

        return dp[l][r] = min(second, first);
    }

    int strangePrinter(string s) {

        n = s.length() ;
        
        dp.resize(n,vector<int>(n+1, -1));
        
        return solve(0, n-1, s);
    }
};