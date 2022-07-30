class Solution {
public:
    
    bool helper( int freq[], int max_freq[] )
    {
        for(int i=0; i<26; i++)
        {
            if(freq[i]<max_freq[i])
                return false;
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string>ans;
        int max_freq[26]={0};
        
        for(string s:words2)
        {
            int freq[26]={0};
            for(char ch: s)
            freq[ch-'a']+=1;
            for(int i=0; i<26; i++)
                max_freq[i]=max(max_freq[i], freq[i]);
            
        }
        
        for(string s: words1)
        {
            
            int freq[26]={0};
            for(char ch: s)
            freq[ch-'a']+=1;
            if(helper(freq,max_freq))
                ans.push_back(s);
            
        }
        return ans;
    }
};