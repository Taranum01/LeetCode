class Solution {
public:
    void MyLetterComb( string digits, vector<string> &res, string nums[], int i, string s){
        
        if(i==digits.length()){
        res.push_back(s);
        return;
        }
        string val= nums[digits[i]-'0'];
        for( int j=0; j<val.length(); j++){
        MyLetterComb( digits, res, nums, i+1, s+val[j]);
        }
            
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.length() ==0)
            return res;
        string nums[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};
        
        MyLetterComb( digits, res, nums, 0, "");
        return res;
    }
};