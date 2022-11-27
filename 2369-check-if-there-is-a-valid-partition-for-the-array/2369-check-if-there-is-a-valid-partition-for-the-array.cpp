class Solution {
public:
    bool validPartition(vector<int>& nums) {
        
        vector<int>dp(nums.size(), -1);
        return func(nums, 0, dp);
    }
        bool func(vector<int> &nums, int i, vector<int>&dp){
            
            if(i==nums.size())
                return true;
            if(dp[i]!=-1) return dp[i];
            
            if(i+1<nums.size() && nums[i+1]==nums[i]){
                
                if(func(nums, i+2, dp)) return dp[i]= true;
                
                if(i+2<nums.size() && nums[i+2]==nums[i]){
                    
                if(func(nums, i+3, dp)) return dp[i]= true;   
            }      
        }
            
        if(i+2<nums.size() && nums[i+1]==nums[i]+1 && nums[i+2]== nums[i]+2)
        {
            if(func(nums, i+3, dp)) return true;
        }
            return dp[i]= false;
    }
};