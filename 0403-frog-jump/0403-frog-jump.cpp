class Solution {
public:

    int n;

    unordered_map<int, int> mp;

    int dp[2001][2001];
    
    bool solve(vector<int>& stones, int curr_stone_idx, int prevJump) {

        if(curr_stone_idx == n-1)
            return true;
        
        bool res = false;
        
        if(dp[curr_stone_idx][prevJump] != -1)
            return dp[curr_stone_idx][prevJump];
        
        for(int nextJump = prevJump-1; nextJump <= prevJump+1; nextJump++) {
            
            if(nextJump > 0) {
                int next_stone = stones[curr_stone_idx] + nextJump;
                
                if(mp.find(next_stone) != mp.end()) {
                    res = res || solve(stones, mp[next_stone], nextJump);
                }
            }
            
        }
        
        return dp[curr_stone_idx][prevJump] = res;
        
    }
    
    bool canCross(vector<int>& stones) {
        
        if(stones[1] != 1)
            return false;
        
        n = stones.size();

        for(int i = 0; i<n; i++) {
            mp[stones[i]] = i;
        }
        
        memset(dp, -1, sizeof(dp));
        
        return solve(stones, 0, 0);
    }
};

