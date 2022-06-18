class WordFilter {
public:
    
    unordered_map<string, int> mapp;
    
    WordFilter(vector<string>& words) {
        
        int n = words.size();
        
        for(int i = 0; i < n; i++)
        {
            string w = words[i];
            
            for(int j = 0; j < w.size(); j++)
            {
                string p = w.substr(0, j + 1);
                
                for(int k = w.size() - 1; k >= 0; k--)
                {
                    string s = w.substr(k);
                    
                    string key = p + "|" + s;
                    
                    mapp[key] = i;
                }
            }
        }
    }
    
    int f(string prefix, string suffix) {
        
        string key = prefix + "|" + suffix;
        
        if(mapp.count(key))
        {
            return mapp[key];
        }
        
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */