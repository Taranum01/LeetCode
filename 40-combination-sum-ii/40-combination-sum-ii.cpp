class Solution {
public:
    vector<vector<int>> ans;
    void help(int i,vector<int>& nums,int t,vector<int>& temp,bool prev){
        if(t==0){
            ans.push_back(temp);
            return;
        }
        if(t<0) return;
        if(i>=nums.size()) return;
        
        //excluding
        help(i+1,nums,t,temp,false);
        
        if(i>0 && nums[i]==nums[i-1] && !prev) return;
        
        //including
        temp.push_back(nums[i]);
        help(i+1,nums,t-nums[i],temp,true);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        help(0,candidates,target,temp,false);
        return ans;
    }
};
