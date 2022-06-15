class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n==0) return false;
        
        while(n>1 && (n&1)==0)
            n>>=1;

       return n==1? true: false; 
    }
};

// return floor(log2(n))== ceil(log2(n))? true:false;

// power of two only one set bit