class Solution {
public:
    int minDeletions(string s) {

        unordered_set<int> st;
        int freq[26] = {0};
      
        for(char &ch : s) {
            freq[ch-'a']++;
        }
        
        int res = 0;
        for(int i=0; i<26; i++) {
            
            while(freq[i] > 0 && st.find(freq[i]) != st.end()) {
                freq[i]--;
                res++;
            }
            st.insert(freq[i]);
        }
        
        return res;
    }
};
