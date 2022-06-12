class Solution {
public:
    bool isAnagram(string s, string t) {
        int freqt[26]={0};
        int freqs[26]={0};
        
        for(char c: s)
            freqt[c-'a']++;
        for(char c: t)
            freqs[c-'a']++;
        
        for (int i=0; i<26;i++)
            if (freqt[i]!= freqs[i])
                return false;
        return true;
    }
};