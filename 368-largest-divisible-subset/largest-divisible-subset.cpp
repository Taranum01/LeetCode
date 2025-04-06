class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>res;
        if(n==0)
            return res;
        
        sort (nums.begin(),nums.end());
        int maximum=1;
        vector<int>dp(n+1,1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    if(maximum<dp[i])
                        maximum=dp[i];
                }
            }
        }
        
        int prev= -1;
        for(int i=n-1; i>=0; i--){
            if(dp[i]==maximum && (prev%nums[i]==0 || prev== -1)){
                res.push_back(nums[i]);
                maximum-=1;
                prev=nums[i];
            }
        }
         return res;
    }
};