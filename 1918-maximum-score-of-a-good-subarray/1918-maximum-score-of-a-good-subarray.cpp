class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {

        int n = nums.size();

        int i = k;
        int j = k;
        int curMin = nums[k];
        
        int res = nums[k];
        
        while(i > 0 || j < n-1) {

            int leftVal;
            int rightVal;
            
            if(i > 0) {
                leftVal = nums[i-1];
            } else {
                leftVal = 0;
            }
            
            if(j < n-1) {
                rightVal = nums[j+1];
            } else {
                rightVal = 0;
            }
            
            if(leftVal < rightVal) { 
                j++;
                curMin = min(curMin, nums[j]);
            } else {
                i--;
                curMin = min(curMin, nums[i]);
            }
            
            res = max(res, curMin * (j-i+1));
        }
        
        return res;
    }
};