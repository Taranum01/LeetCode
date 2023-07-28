class Solution {
public:

    int n;
    int dp[23][23];
    
  
    int maxDiff(vector<int>& nums, int l, int r) {
        
        if(l == r)
            return nums[l];
        
        if(dp[l][r] != -1)
            return dp[l][r];
        
        int take_left  = nums[l] - maxDiff(nums, l+1, r);
        int take_right = nums[r] - maxDiff(nums, l, r-1);
        
        return dp[l][r] = max(take_left, take_right);
    }
    
    bool PredictTheWinner(vector<int>& nums) {

        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return maxDiff(nums, 0, n-1) >= 0;
            
    }
};