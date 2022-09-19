class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>mp;
        
        for(string p: paths){
            string s;
            int i;
            for(i=0; i<p.size() && p[i]!=' '; i++)
                s+=p[i];
            s+='/';
            i++;
                
          while(i<p.size()){
            string file,data;
            
            while(i<p.size() && p[i]!='(')
                file+=p[i++];
            
            while(i<p.size() && p[i]!=' ')
                data+=p[i++];
            
            mp[data].push_back(s+file);
            ++i;
        }
        }
    
        for(auto &a: mp){
        if(a.second.size()>1)
            ans.push_back(a.second);
        }
        return ans;
    }
};