class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        unordered_map<string,int>dp;
        
        int ans=0;
        
        sort(words.begin(), words.end(), sortbylen);
        
        for(string word: words){
            
            for(int i=0; i<word.length(); i++){
                
            string pre= word.substr(0,i)+word.substr(i+1);
            dp[word]=max(dp[word], dp[pre]+1);
            
            }
            ans= max(ans, dp[word]);
        }
        return ans;
    }
    
    static bool sortbylen(string &s1, string &s2){
        
        return s1.length()<s2.length();
    }
};