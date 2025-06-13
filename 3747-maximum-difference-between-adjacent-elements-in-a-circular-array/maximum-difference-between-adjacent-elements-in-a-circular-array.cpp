class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {

        int res = 0;

        for(int i = 0; i < nums.size() - 1; ++i){
            
            if(abs(nums[i + 1] - nums[i]) > res) 
            res = max(res, abs(nums[i + 1] - nums[i]));
            cout << res;
        }

        if(abs(nums[0] - nums[nums.size() - 1]) > res) 
        res = max(res, abs(nums[0] - nums[nums.size() - 1])); 
        
        return res;
    }
};