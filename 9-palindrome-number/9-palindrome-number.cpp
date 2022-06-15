class Solution {
public:
    bool isPalindrome(int x) {
        
        int temp=x;
        long long a=0;  
    
        while(temp>0){
        
        int r=temp%10;  // rightmost digit of x
        a=a*10+r;       
        temp/=10;       // reducing the size of temp by one's place
    }
    
        return a==x; 
        
    }
};

//     bool isPalindrome (int x) {
//     string s1=to_string(x);
//     string s2=s1;
//     reverse(s2.begin(), s2.end());
//     if(s1!=s2){
//         return false;
//     }
//     return true;
// }