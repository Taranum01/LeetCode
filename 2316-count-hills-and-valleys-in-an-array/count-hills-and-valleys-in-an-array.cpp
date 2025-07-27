class Solution {
public:
    
    int countHillValley(vector<int>& nums) {
       
    int n=nums.size();
    int count=0;
        
    for (int i=1, j=0; i<n-1; i++)
        
        if ((nums[j]<nums[i] && nums[i]>nums[i+1]) || 
            (nums[j]>nums[i] && nums[i]<nums[i+1])) {
            
            count++;
            j=i;
        }   
        
    return count;
}
};