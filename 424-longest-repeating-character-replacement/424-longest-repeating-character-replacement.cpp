class Solution {
public:
    int characterReplacement(string str, int k) {
        
        int n = str.size();
        
        vector<int> freq(26,0); 
        int max_freq = 0;
        int ans = -1;
        int lo = 0, hi = 0; 

        while(hi < n) {
            freq[str[hi] - 'A']++; 
            max_freq = max(max_freq,freq[str[hi] - 'A']); 
            
            while((hi - lo + 1) - k > max_freq) {

                freq[str[lo] - 'A']--;
                lo++;
            }
            ans = max(ans,(hi-lo+1));
            hi++;
        }
        return ans;
    }
};