class Solution {
public:

    int n;
    int dp[23][23];

    int solve(vector<int>& nums, int l, int r) {
        
        if(l>r)
            return 0;
        
        if(l==r)
            return nums[l];
        
        if(dp[l][r] != -1)
            return dp[l][r];
        
        int take_left  = nums[l] + min(solve(nums, l+2, r), solve(nums, l+1, r-1));
        
        int take_right = nums[r] + min(solve(nums, l, r-2), solve(nums, l+1, r-1));
        
        
        return dp[l][r] = max(take_left, take_right);
        
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        
        memset(dp, -1, sizeof(dp));
        
        n = nums.size();
        
        int total = accumulate(begin(nums), end(nums), 0);
        
        int player1 = solve(nums, 0, n-1);
        int player2 = total - player1;
        
        return player1 >= player2;
    }
};