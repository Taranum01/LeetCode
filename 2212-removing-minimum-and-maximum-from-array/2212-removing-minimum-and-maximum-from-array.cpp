class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int n = nums.size();

        int maxidx = 0, minidx = 0;

        int mini = INT_MAX, maxi = INT_MIN ;
		
        for (int i = 0; i < n; i++){

            if(nums[i] < mini){
                mini = nums[i]; 
                minidx = i;
            }

            if(nums[i]>maxi){
                maxi=nums[i]; 
                maxidx=i; 
            }
        }
     
        int front = max(maxidx, minidx) + 1;
		
        int back = n - min(minidx, maxidx);
		
		
        int frontBack = (min(minidx, maxidx)+ 1) + (n - max(minidx, maxidx));
		
       return min(min(front, back), frontBack);
        
    }
};