class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;

        for(int &num : nums) {

            bool found = false;
            for(int x = 0; x < num; x++) {
                if((x | (x+1)) == num) {
                    res.push_back(x);
                    found = true;
                    break;
                }
            }
            if(!found)
                res.push_back(-1);

        }

        return res;
    }
};