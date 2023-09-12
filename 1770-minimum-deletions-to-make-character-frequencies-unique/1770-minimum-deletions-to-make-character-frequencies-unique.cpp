class Solution {
public:
    int minDeletions(string s) {

        int freq[26] = {0};
        
        for(char &ch : s) {
            freq[ch-'a']++;
        }

        sort(begin(freq), end(freq));
        
        int res = 0;
        
        for(int i=24; i>=0 && freq[i]>0; i--) {
            
            if(freq[i] >= freq[i+1]) {
                
                int prev = freq[i];
                
                freq[i] = max(0, freq[i+1]-1);
                
                res += (prev - freq[i]);
                
            }
            
        }
          
        return res;
    }
};