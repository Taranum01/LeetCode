class Solution {
public:
    int minimumIndex(vector<int>& nums) {

        int n = nums.size();

        int ele  = -1;
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(count == 0) {
                ele = nums[i];
                count = 1;
            } else if(nums[i] == ele) {
                count++;
            } else {
                count--;
            }
        }

        int eleCount = 0;

        for(int &num : nums) {
            if(num == ele) {
                eleCount++;
            }
        }

        count = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == ele) {
                count++;
            }            
            int remainingCount = eleCount - count;

            int n1 = i+1;
            int n2 = n-i-1;

            if(count*2 > n1 && remainingCount*2 > n2) {
                return i;
            }
        }


        return -1;

    }
};
