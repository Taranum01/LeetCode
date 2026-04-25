class Solution {
public:
    bool isPalindrome(string s) {
        
        vector<char>v;
		
        for(auto c:s){
            if(c>='a'&& c<='z' || c>='0'&&c<='9'){
                v.push_back(c);
            }
            else if(c>='A'&& c<='Z'){
                v.push_back(c-'A'+'a');
            }
        }
	
      int i=0,j=v.size()-1;
      while(j>=i){
        if(v[i]!=v[j]){
            return false;
			break;
        }
        i++;
        j--;
    }
        return true;
    }
};
