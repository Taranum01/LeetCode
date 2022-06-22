class Solution {
public:
    
    int deleteAndEarn(vector<int>& nums) {
        int n = *max_element(nums.begin(), nums.end());
        vector<int>sums(n+1,0); 
    
        for(int i=0; i<nums.size(); i++){
           sums[nums[i]]+=nums[i]; 
            
		   //storing (by index) at each index count of that element in nums;
        }
	
        int dp[n+1];
        dp[0]=sums[0];
        dp[1]=max(sums[1],sums[0]);
        for(int i=2; i<n+1; i++){
            dp[i]=max(sums[i]+dp[i-2], dp[i-1]); 
        }
        return max(dp[n-1],dp[n]);
    }
};