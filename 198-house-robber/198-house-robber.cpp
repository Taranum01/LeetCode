class Solution {
public:
    int rob(vector<int>& nums) {
      int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        
        int h1=nums[0];
        int h2=max(h1, nums[1]);
        
        for(int i=2; i<n; i++)
        {
            int temp=h2;
            h2= max(h2, h1+nums[i]);
            h1=temp;
        }
        
        return h2;
        
    }
};