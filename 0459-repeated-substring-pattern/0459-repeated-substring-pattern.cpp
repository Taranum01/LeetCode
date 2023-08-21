class Solution {
public:
    
    bool isSafe(string s, string str){
        
        for(int i=0; i<s.length(); i+=str.length()){
        
            string curr= s.substr(i,str.length());
            if(curr!=str)
            return false;
        }
        return true;
        
    }
    bool repeatedSubstringPattern(string s) {
        
        string str="";
        
        for(int i=0; i<s.length()/2; i++){
            
            str+=s[i];
            if(s.length()%str.length()==0)
            {
                
            bool x= isSafe(s.substr(i+1), str);
            if(x) 
                return true;
            }
          }

        return false;
    }
};