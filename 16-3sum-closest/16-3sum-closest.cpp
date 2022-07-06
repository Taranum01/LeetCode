class Solution {
public:
    
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        int ans = 0;
        
        for(int i=0; i<n; i++)
        {
            int start=i+1;
            
            int end=n-1;
            
            while(start<end)
            {
                int diff = abs(target - (nums[i] + nums[start] + nums[end]));
                    if(diff < min_diff)
                {
                    min_diff = diff;
                    ans = nums[i] + nums[start] + nums[end];
                }
                // sum == target
                if(min_diff == 0)
                    return ans;
                
                if(nums[i] + nums[start] + nums[end] <= target)  
                {
                    start++;
                }
                else  
                {
                    end--;
                }
            }
            // skip duplicates
            while(i < n - 1 && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
        return ans;
    }
};