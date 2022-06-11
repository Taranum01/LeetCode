class NumArray {
public:
      
       vector<int> prefix_sum;
    
       NumArray(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++)
        {
           nums[i] = nums[i] + nums[i-1];
        }
        prefix_sum = nums;
        }
    
       int sumRange(int left, int right) {
        
        if(left == 0)
            return prefix_sum[right];
        return prefix_sum[right] - prefix_sum[left-1];
        }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */