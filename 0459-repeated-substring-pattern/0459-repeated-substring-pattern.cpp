class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        int n = s.length();

        for(int l = 1; l <= n/2; l++) {
            
            if(n % l == 0) {

                int count = n/l;
                
                string pattern   = s.substr(0, l);
                string newStr = "";

                while(count--) {
                    
                    newStr += pattern;
                }
                
                if(newStr == s)
                    return true;
            }
            
        }
        
        return false;
    }
};