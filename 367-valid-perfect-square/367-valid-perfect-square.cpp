class Solution {
public:
    bool isPerfectSquare(int num) {
        
    long int high=100000, low=1, mid, sq;
        
        while(low<=high){
            
            mid= low+(high-low)/2;
            sq= mid*mid;
            
            if(sq==num)
                return true;
            
            else if(sq>num)
                high= mid-1;
            
            else low= mid+1;
        }
        return false;
    }
};