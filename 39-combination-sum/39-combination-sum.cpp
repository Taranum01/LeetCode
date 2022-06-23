class Solution {
public:
    
    vector<vector<int>>ans;
    void helper(int i, vector<int>&C, int T, vector<int>&sol){
        if(T==0)
        {
            ans.push_back(sol);
            return;
        }
        if(T<0){
            return;
        }
        if(i==C.size()){
            return;
        }
        //skip ith element
        
        helper(i+1, C,T,sol);
        
        //pick ith element
        sol.push_back(C[i]);
        helper(i, C, T-C[i],sol);
        //backtrack
        
        sol.pop_back();
        
    }
    vector<vector<int>> combinationSum(vector<int>& C, int T) {
        vector<int>sol;
        helper(0,C,T,sol);
        return ans;
    }
};