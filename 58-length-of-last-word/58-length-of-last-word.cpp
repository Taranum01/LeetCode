class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int n = s.size()-1, counter = 0;
        
        while(s[n] == ' ') n--;    
        
        while(n >= 0 && s[n] != ' ') {
            
            counter++;
            n--;
        }
        
        return counter;
    }
};