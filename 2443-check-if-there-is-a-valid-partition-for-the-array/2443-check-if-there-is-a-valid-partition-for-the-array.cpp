class Solution {
public:

    int n;
    int dp[100001];
    bool solve(vector<int>& nums, int i) {
        
        if(i >= n)
            return true;
        
        if(dp[i] != -1)
            return dp[i];
        
        bool res = false;
        
        if(i+1 < n && nums[i] == nums[i+1])
            res |= solve(nums, i+2);
        
        if(i+2 < n && nums[i] == nums[i+1] && nums[i+1] == nums[i+2])
            res |= solve(nums, i+3);
        
        if(i+2 < n && nums[i+1] - nums[i] == 1 && nums[i+2] - nums[i+1] == 1)
            res |= solve(nums, i+3);
        
        return dp[i] = res;
        
    }
    
    bool validPartition(vector<int>& nums) {

        n = nums.size();
        
        memset(dp, -1, sizeof(dp));
        
        return solve(nums, 0);
        
    }
};