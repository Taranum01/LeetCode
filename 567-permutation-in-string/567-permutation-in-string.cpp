class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n= s1.size(), m= s2.size();
        if(s2.size() < s1.size()) return false;
        vector<int> freq(26,0), window(26,0);
        for(char c: s1){
            freq[c-'a']+=1;
        }
        int i;
        for(i=0; i<n; i++){
            window[s2[i]-'a']+=1;
            
        }
        for( ;i<m; i++){
            if(freq==window) return true;
        window[s2[i]-'a']+=1;
        window[s2[i-n]-'a']-=1;
        }
        if(freq==window) return true;
        return false;
        
            
    }
};