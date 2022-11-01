class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        
        map<int,int>mp;
        int count=0;
        int ans=0;
        
        for(int i:rolls){
            mp[i]++;
            if(mp[i]==1) count++;
            if(count==k){
                ans++;
                mp.clear();
                count=0;
            }
        }
        return ans+1;
    }
};