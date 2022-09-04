class Solution {
public:
    
    int numJewelsInStones(string jewels, string stones) {
        
        map<char,int>mp ;
        for (char c : jewels)
        {
        mp[c] = 1 ;
        }
        int ans = 0 ;
        for(char c : stones)
        {
        if(mp[c] == 1)
        ans++ ;

        }
        return ans ; 
        }
};