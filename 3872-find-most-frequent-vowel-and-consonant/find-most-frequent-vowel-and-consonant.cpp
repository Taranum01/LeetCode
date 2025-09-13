class Solution {
public:
    int maxFreqSum(string s) {

        int freq[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        int maxCon = 0, maxVow = 0;

        for (int i = 0; i < 26; i++) {

            if ('a' + i == 'a' || 'a' + i == 'e' || 'a' + i == 'i' ||
                'a' + i == 'o' || 'a' + i == 'u')
                maxVow = max(freq[i], maxVow);

            else {
                maxCon = max(maxCon, freq[i]);
            }
        }
        
        return maxCon + maxVow;
    }
};