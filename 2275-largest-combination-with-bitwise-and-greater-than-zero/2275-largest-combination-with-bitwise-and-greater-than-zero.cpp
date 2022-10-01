class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        int ans=0;
        for(int i=0; i<32; i++){
            int count=0;
            for(int j=0; j<candidates.size(); j++){
                if(candidates[j]&(1<<i))
                    count++;
            }
            ans= max(count,ans);
        }
        return ans;
    }
};