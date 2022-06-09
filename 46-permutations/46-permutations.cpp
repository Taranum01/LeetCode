class Solution {
public:
    vector<vector<int>>ans;
    void perm(vector<int> &nums, int i)
    {
        if (i==nums.size())
        {
            ans.push_back(nums);
            return;
            
        }
        for( int j=i; j<nums.size(); j++)
        {
            swap(nums[i], nums[j]);
            perm(nums, i+1);
            swap(nums[i], nums[j]);
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums,0);
        return ans;
    }
};