class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        int sum=0;
        double res;
        for(int i=0; i<k; i++)
            sum+=nums[i];
        res=sum;
        for(int i=k; i<nums.size(); i++){
            sum=sum-nums[i-k];
            sum=sum+nums[i];
            if(sum>res) res=sum;
            
        }
        return res/k;
    }
};