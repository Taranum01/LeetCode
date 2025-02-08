class Solution {
public:

    string longestPalindrome(string s) {

        int n = s.length();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int maxL = 1;
        int start = 0;
        
        for(int i = 0; i<n; i++)
            dp[i][i] = true;
      
        
        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i + L - 1;
                
                if(s[i] == s[j] && (dp[i+1][j-1] || L == 2)) {
                    dp[i][j] = true;
                    if(L > maxL) {
                        maxL = L;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start, maxL);
    }
};