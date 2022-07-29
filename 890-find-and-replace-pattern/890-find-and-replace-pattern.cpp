class Solution {
public:
    
    bool is_check(string& word, string& pattern)
    {
        int n = word.size();
        
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;
        
        bool flag1 = true;
        bool flag2 = true;
        
        for(int i = 0; i < n; i++)
        {
            if(mp1.count(pattern[i]))
            {
                if(mp1[pattern[i]] != word[i])
                {
                    flag1 = false;
                    
                    break;
                }
            }
            else
            {
                mp1[pattern[i]] = word[i];
            }
        
            if(mp2.count(word[i]))
            {
                if(mp2[word[i]] != pattern[i])
                {
                    flag2 = false;
                    
                    break;
                }
            }
            else
            {
                mp2[word[i]] = pattern[i];
            }
        }
        
        return (flag1 && flag2);
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> res;
        for(auto word : words)
        {
            if(is_check(word, pattern))
            {
                res.push_back(word);
            }
        }
        
        return res;
    }
};