class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>last_occ(26,0);
            for(int i=0; i<s.length(); i++)
                last_occ[s[i]-'a']= i;
        
        vector<int>result;
        int start=0;
        int last=0;
        for(int i=0; i<s.length(); i++){
            last=max(last,last_occ[s[i]-'a']);
        if(i==last) {
            result.push_back(i-start+1);
        start=i+1;
        
    }
      }
      
      return result;
        
    }
};