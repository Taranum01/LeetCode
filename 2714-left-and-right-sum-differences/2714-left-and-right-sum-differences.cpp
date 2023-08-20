class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int sum = 0;

        for(auto it : nums)
            sum += it;

        int x = 0;

        vector<int> ans;
        
        for(int i = 0; i<nums.size(); i++)
        {
            int leftsum = x;
            int rightsum = sum - (x + nums[i]);
            ans.push_back(abs(leftsum - rightsum));
            x += nums[i];
        }
        return ans;
        
    }
};