class Solution {
public:
    string fractionToDecimal(int num, int denm) 
    {
        if(num == 0) return "0";
        
        string ans;
        
        ans = (num > 0)^(denm > 0) ? "-":"";       
        
        long n = abs(num);        
        long d = abs(denm);
        
        ans += to_string(n/d);          
        
        n = n%d;
        
        if(!n) return ans;              
        
        ans += ".";
        
        
        unordered_map<long, int> mp;
        
        while(n)        
        {   
            if(mp[n])     
            {
                ans.insert(mp[n], "(");    
                ans += ")";                
                break;          
            }
            else{
                mp[n] = ans.size();     
                n *= 10;
                ans += to_string(n/d);  
                n = n%d;              
            }
        }
        
        return ans;
    }
};