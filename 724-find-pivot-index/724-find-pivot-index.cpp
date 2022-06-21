class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
       int total=0;
        
        for(int i=0;i<nums.size();i++)
            
            total+=nums[i];
        
        int leftsum=0;
        
        int rightsum=total;
        
        for(int i=0;i<nums.size();i++)
        {
            rightsum-=nums[i];
            
            if(leftsum==rightsum)
                
                return i;
            
            leftsum+=nums[i];
        }
        return -1; 
    }
};