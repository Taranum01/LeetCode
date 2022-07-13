class Solution {
public:
   vector<vector<int>>ans;
    void helper(int i, int T, vector<int>&sol, int k){
        if(T==0 && k==0)
        {
            ans.push_back(sol);
            return;
        }
        if(T<0 || k<0){
            return;
        }
        if(i==10){
            return;
        }
        //skip ith element
        
        helper(i+1,T,sol,k);
        
        //pick ith element
        sol.push_back(i);
        helper(i+1,T-i,sol, k-1);
        //backtrack
        
        sol.pop_back();
        
    }
    vector<vector<int>> combinationSum3(int k, int T) {
        vector<int>sol;
        helper(1,T,sol,k);
        return ans;
    }
};