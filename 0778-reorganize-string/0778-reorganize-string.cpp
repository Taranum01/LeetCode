class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.length();
        
        vector<int> count(26, 0);

        int maxFreq   = 0;

        char maxFreqCh;

        for(char &ch : s) {
            count[ch-'a']++;
            
            if(count[ch-'a'] > maxFreq) {
                maxFreq = count[ch-'a'];
                maxFreqCh = ch;
            }
            
            if(count[ch-'a'] > (n+1)/2)
                return "";
        }

        string res = s;
        
        int idx = 0;

        while (count[maxFreqCh-'a'] != 0) {
            res[idx ] = maxFreqCh;
            idx += 2;
            count[maxFreqCh-'a']--;
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            
            while (count[ch-'a'] > 0) {
                if (idx >= n) {
                    idx = 1;
                }
                res[idx] = ch;
                idx += 2;
                count[ch-'a']--;
            }
        }

        return res;
    }
};