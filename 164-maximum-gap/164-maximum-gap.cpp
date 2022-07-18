class Solution {
public:
    
    int maximumGap(vector<int>& nums) {
        
        int n = nums.size();
        if(n<2)
            return 0;
        
        // maximum and minimum element of array
        
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        
        // find gap
        
        int gap = ((maxi - mini) / (n - 1))+1;
        
        // store the min of bucket
        
        vector<int> min_bucket(n-1, INT_MAX);
        
        // store the max of bucket
        
        vector<int> max_bucket(n-1, INT_MIN);
        
        // fill the min_bucket and max_bucket
        
        for(int i=0; i<n; i++)
        {
            if(nums[i]!=mini && nums[i]!=maxi)
            {
                // index of bucket
                int buc_idx = (nums[i]-mini)/gap;
                
                min_bucket[buc_idx] = min(min_bucket[buc_idx], nums[i]);
                max_bucket[buc_idx] = max(max_bucket[buc_idx], nums[i]);
            }
        }
        
        // now traverse over buckets and find max_gap
        
        int max_gap = INT_MIN;
        
        // store max of prev bucket
        
        int max_prev = mini;
        
        // find max gap
        
        for(int i=0; i<n-1; i++)
        {
            // if bucket is not empty
            
            if(min_bucket[i] != INT_MAX && max_bucket[i] != INT_MIN)
            {
                int curr_gap = min_bucket[i] - max_prev;
                max_gap = max(max_gap, curr_gap);
                max_prev = max(max_prev, max_bucket[i]);
            }
        }
        
        max_gap = max(max_gap, maxi-max_prev);
        return max_gap;
    }
};