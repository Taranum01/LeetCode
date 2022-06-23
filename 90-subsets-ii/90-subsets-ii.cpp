class Solution {
public:
    
    void helper(int i, vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,bool prev)
    {
        if(i==nums.size()){
            ans.push_back(temp);
        }
        else {
            //to ignore ith element
            helper(i+1,nums,temp,ans,false);
            if(i>0 && nums[i]==nums[i-1] &&(!prev))
            return;
            
            //to take the ith element
            temp.push_back(nums[i]);
            helper(i+1,nums,temp,ans,true);
            temp.pop_back();
        }
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
            vector<vector<int>>ans;
            vector<int>temp;
            helper(0,nums,temp,ans,false);
            return ans;
        }
};