class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        sort(pairs.begin(),pairs.end());
        
        vector<int>n;
        
        for(int i=0;i<pairs.size();i++)
        {
            n.push_back(pairs[i][1]);
        }
        
        vector<int>dp(n.size(),1);
        dp[0] = 1;
        
        for(int i=1;i<n.size();i++)
        {
            for(int j=0;j<i;j++)
                
            {
                        if(pairs[j][1] < pairs[i][0])
                        {
                        dp[i] = dp[j] + 1;
                        }
            }
        }
        return dp[n.size()-1];
    }
};