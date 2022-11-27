class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        set<int>s(nums.begin(), nums.end());
        if(*s.begin()==0) return s.size()-1;
        return s.size();
    }
};