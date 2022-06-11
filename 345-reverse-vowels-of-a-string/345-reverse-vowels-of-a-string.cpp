class Solution {
public:

    bool isVowel(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' ||           c=='O' || c=='U' ){
             return true;
         } 
        else {
            return false;
        }
    }
   
   string reverseVowels(string s) 
       {
      
       int l=0, r=s.size()-1;
       
        while(l<=r)
        {
            if((isVowel(s[l])== true && isVowel(s[r])== true))
            {
                swap(s[l],s[r]);
                l++;
                r--;
            }
            else if(isVowel(s[l])== true){
                r--;
            }
            else {
                l++;
            }
        }
        return s;
    }

};
