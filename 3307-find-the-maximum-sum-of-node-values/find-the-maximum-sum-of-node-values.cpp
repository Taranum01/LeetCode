class Solution {
public:

    typedef long long ll;

    ll maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {

        vector<int> profit;
        ll normalSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {

            profit.push_back((nums[i] ^ k) - nums[i]);
            normalSum += 1ll * nums[i];
        }
        
        sort(profit.begin(), profit.end(), greater<int>());
        
        for (int i = 0; i < profit.size()-1; i += 2) {

            ll pairSum = profit[i] + profit[i + 1];
            
            if (pairSum > 0) {
                normalSum += pairSum;
            }
        }
        return normalSum;
    }
};

