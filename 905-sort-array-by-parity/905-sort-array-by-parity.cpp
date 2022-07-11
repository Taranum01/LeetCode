class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        vector<int>odd;
        vector<int>even;
        
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]%2==0){
                even.push_back(nums[i]);
            }
            else {
                odd.push_back(nums[i]);
            }
        }
        even.insert(even.end(),odd.begin(), odd.end());
        return even;
        
    }
};