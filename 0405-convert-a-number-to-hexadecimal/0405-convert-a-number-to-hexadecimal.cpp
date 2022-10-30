class Solution {
public:
    string toHex(int num) {
        
        unsigned int n = num;
        string res;
        string hexaDec = "0123456789abcdef";
        
        if (n==0) {
        return "0";
        }
        while(n>0){
            
            res += hexaDec[n%16];
            n/=16;
            
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};