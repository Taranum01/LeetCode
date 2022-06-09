class Solution {
public:
    
    void permute(string s,vector<string> &res,int i){
        if(i==s.length()){
            res.push_back(s);
            return;
        }
        if(isalpha(s[i])){
            s[i]=toupper(s[i]);
            permute(s,res,i+1);
            s[i]=tolower(s[i]);
            permute(s,res,i+1);
        }else{
            permute(s,res,i+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        permute(s,res,0);
        return res;
        
    }
};
