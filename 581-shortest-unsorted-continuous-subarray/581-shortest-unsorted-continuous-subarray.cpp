class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int low=0, high=nums.size()-1;
        
        while(low+1 < nums.size() && nums[low] <= nums[low+1]) low++;
        while(high-1 >= 0 && nums[high-1]<= nums[high] )high--;
        
        if(low==nums.size()-1) return 0;
        
        int minEle= INT_MAX, maxEle= INT_MIN;
        
        for(int i=low; i<=high; i++){
            minEle= min(minEle, nums[i]);
            maxEle= max(maxEle, nums[i]);
        }
        
        while(low-1>=0 && nums[low-1]>minEle) low--;
        while(high+1 <=nums.size()-1 && nums[high+1]< maxEle)high++;
        
        return high-low+1;
        
    }
};