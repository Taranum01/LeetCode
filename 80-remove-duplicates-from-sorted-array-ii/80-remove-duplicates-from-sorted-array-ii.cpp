class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i=0;
        for(auto element:nums){
            if(i==0 || i==1 || nums[i-2]!=element)
            {
                nums[i]=element;
                i+=1;
            }
        }
        
        return i;
    }
};