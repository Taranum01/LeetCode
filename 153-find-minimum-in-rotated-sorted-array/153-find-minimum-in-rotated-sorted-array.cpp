class Solution {
    int search(vector<int>&nums, int left, int right){
        if(left==right) return nums[left];
        int mid= left+(right-left)/2;
        if(nums[mid]>nums[right]) return search(nums, mid+1, right);
        if(nums[mid]<nums[right]) return search(nums, left, mid);
        return nums[right];
        
    }
        
public:
    int findMin(vector<int>& nums) {
        return search(nums,0,nums.size()-1);
    }
};