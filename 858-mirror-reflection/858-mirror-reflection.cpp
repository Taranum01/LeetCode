class Solution {
public:
    int mirrorReflection(int p, int q) {
        
        // make atleast one of them odd
        
        while(p % 2 == 0 && q % 2 == 0)
        {
            p = p >> 1;
            q = q >> 1;
        }
        
        // if p is even and q is odd
        
        if(p % 2 == 0 && q % 2 == 1)
        {
            return 2;
        }
        
        // if p is odd and q is even
        
        else if(p % 2 == 1 && q % 2 == 0)
        {
            return 0;
        }
        
        // if p is odd and q is odd
        
        else if(p % 2 == 1 && q % 2 == 1)
        {
            return 1;
        }
        
        return 0;
    }
};