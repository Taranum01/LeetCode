class Solution {
public:
    
    bool isInteger(string s)
    {
        if(s.empty())
            return false;
        
        if(s[0]=='+' or s[0]=='-')
            
            s = s.substr(1);
        
        // atleast one digit
        
        for(int i=0;i<s.length();i++) {
            
            if(s[i]>='0' and s[i]<='9')
                continue;
            
            return false;
        }
        
        return !s.empty();
    }
    
    bool isDecimal(string s){
        
        if(s.empty())
            return false;
        
        if(s[0]=='+' or s[0]=='-')
            s = s.substr(1);
        
        int c= count(s.begin(),s.end(),'.');
        
        if(c==1){
            
            int index = 0;
            
            for(int i=0;i<s.length();i++) {
                
                if(s[i]=='.'){
                    index = i;
                    break;
                }
            }
            
            for(int i=0; i<index; i++) {
                
                if(s[i]>='0' and s[i]<='9')
                    continue;
                
                return false;
            }
            
            for(int i=index+1; i<s.length(); i++){
                
                if(s[i]>='0' and s[i]<='9')
                    continue;
                return false;
                
            }
            
            return s.length()>1;
        }
        
        return false;
        
    }
    
    bool isNumber(string s) {
        int count = 0;
        int n = s.length();
        
        //'e' or 'E'
        
        for(int i=0;i<n;i++)
            
            count+=(s[i]=='e' or s[i]=='E');
        
        if(count>1)
            
            return false;
        
        if(count){
            
            // position of 'e' or 'E'
            int index = 0;
            
            for(int i=0;i<n;i++){
                if(s[i]=='e' or s[i]=='E'){
                    index = i;
                    break;
                }
            }
            
            if(!isInteger(s.substr(index+1)))
                
                return false;
            
            // take decimal string
            
            s = s.substr(0,index);
        }
      
        return isInteger(s) or isDecimal(s);
    }
};