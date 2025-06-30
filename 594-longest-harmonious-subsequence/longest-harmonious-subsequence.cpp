class Solution {
public:
    int findLHS(vector<int>& nums) {

        unordered_map<int, int> mp;

        int res = 0;

        for(int &num : nums) {
            mp[num]++;
        }

        for(int &num : nums) {

            int minNum = num;
            int maxNum = num+1;

            if(mp.count(maxNum)) {
                res = max(res, mp[minNum] + mp[maxNum]);
            }
        }

        return res;
    }
};