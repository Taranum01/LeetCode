class Solution {
public:
    int longestIdealString(string s, int k) {
        
        vector<int>dp(26,0);
        int ans=0;
        
        for(int i=0; i<s.size(); i++){
            
            int element= s[i]-'a';
            
            for(int j=element; j>=0 && j>=element-k; j--){
                dp[element]= max(dp[element], dp[j]+1);
            }
            
            for(int j=element+1; j<26 && j<=element+k; j++){
                dp[element]= max(dp[element], dp[j]+1);
            }
            ans= max(ans, dp[element]);
        }
        return ans;
    }
};