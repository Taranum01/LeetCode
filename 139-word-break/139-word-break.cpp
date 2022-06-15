class Solution {
public:
    
    unordered_map<string, int>dp;
    
     int solve(string s, vector<string> &wordDict){
        int len=s.length();
        if(len==0)return 1;
         if(dp[s]!=0) return dp[s];
         
      for(int i=1; i<=len; i++){
        int flag=0;
          string ss= s.substr(0,i);
         for(int j=0; j<wordDict.size();j++){
             if(ss.compare(wordDict[j])==0){
                 flag=1;
                 break;
             }
         } 
          if(flag==1 and solve(s.substr(i,len-i),wordDict)==1) return dp[s]=1;
          
      }
             return dp[s]=-1;
         
     }
    
     int wordBreak(string s, vector<string>& wordDict) {
        
        int x= solve(s, wordDict);
         if(x==1) return 1;
         else return 0;
    }
}; 