class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int>dp(n);
        dp[0]=1;
        int p1=0, p2=0, p3=0;
        
        for(int i=1;i<n;i++){
            
            int multipleof2= dp[p1]*2;
            int multipleof3= dp[p2]*3;
            int multipleof5= dp[p3]*5;
           
        dp[i]= min(multipleof2, min(multipleof3, multipleof5));
            
            if(dp[i]==multipleof2)p1++;
            if(dp[i]==multipleof3)p2++;
            if(dp[i]==multipleof5)p3++;
                
        }
        return dp[n-1];
    
    }
};