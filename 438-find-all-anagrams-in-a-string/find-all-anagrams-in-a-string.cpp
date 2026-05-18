class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int len = s.size();
        int window = p.size();
        
        vector<int> ans;
        
        if(window > len)return ans; 
        
        vector<int> shash(26,0);  
        vector<int> phash(26,0); 
        
        for(int i=0;i<window;i++)
        {
            shash[s[i]-'a']++;       
            phash[p[i]-'a']++;
        }
    
        if(shash == phash)ans.push_back(0);
        
        for(int i=window;i<len;i++)
        {
            shash[s[i-window]-'a']--;
            shash[s[i]-'a']++;
            
            
            if(shash == phash)ans.push_back(i-window+1);
        }
    
        return ans;
       
    }
};