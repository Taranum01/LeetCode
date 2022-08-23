class Solution {
public:
    
   bool solve(string s1, string s2, unordered_map<string, bool> &mp) {
       
	   if(s1 == s2) return true;
       
	   string code = s1 + '$' + s2;
       
	   if(mp.find(code) != mp.end())
           
	   return mp[code];
       
	for(int k = 1; k < s1.size(); k++) {
		
		if((solve(s1.substr(0, k), s2.substr(0, k), mp) &&
            
		solve(s1.substr(k), s2.substr(k), mp)) ||

		(solve(s1.substr(0, k), s2.substr(s1.size() - k), mp) &&
         
		solve(s1.substr(k), s2.substr(0, s1.size() - k), mp)))
            
		return mp[code] = true;
	}
       
	return mp[code] = false;
}

bool isScramble(string s1, string s2) {
    
	unordered_map<string, bool> mp;
    
	return solve(s1, s2, mp);
}
    
};

