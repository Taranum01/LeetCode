class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        map<int,int>mp;

        for(vector<int>v: trips){
            int start=v[1];
            int end=v[2];
            mp[start]+=v[0];
            mp[end]-=v[0];
        }

        int sum=0;
        for(auto it=mp.begin(); it!=mp.end(); it++){
            sum+=it->second;
            if(sum>capacity) return false;
        }
        return true;
    }
};