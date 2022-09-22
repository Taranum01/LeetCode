class Solution {
public:
    int minSteps(string s, string t) {
        
        map<char,int>mp;
        
        for(auto a: s) mp[a]++;
        for(auto a: t) mp[a]--;
        
        int count=0;
        
        for(auto a: mp)
            
            count+=abs(a.second);
        
        return count/2;
        
    }
};