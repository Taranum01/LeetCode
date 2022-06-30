class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int start=0;
        int end= nums.size()-1;
        int count=0;
        while(start<end)
        {
            count+= nums[end]-nums[start];
            start++;
            end--;
        }
        return count;
    }
};