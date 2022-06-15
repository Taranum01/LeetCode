class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        int n=s.size();
        vector<string> res;
        map<string,int> m;
        
        for(int i=0;i<n-9;i++){
            string temp=s.substr(i,10);
            m[temp]++;
        }
                    
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second>1) 
                res.push_back(it->first);           
        }
        
      return res;  
    }
};