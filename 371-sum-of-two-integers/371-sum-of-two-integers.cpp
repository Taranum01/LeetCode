class Solution {
public:
   int getSum(int a, int b) {
       
        if (b==0) return a;
        int sum = (a^b);
        int carry = ((unsigned)(a&b)<<1); // Left shift in int not possible for negative int, so casted to unsigned
        
        return getSum(sum, carry);
    }
};
