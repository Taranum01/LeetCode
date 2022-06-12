class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& str) {
        vector<vector<string>> result;
        if(str.size()==0)
            return result;
        unordered_map<string,vector<string>>map;
        for(string s:str){
            string key= s;
            std::sort(key.begin(),key.end());
                map[key].push_back(s);
    }
    for (auto p:map)
        result.push_back(p.second);
    return result;
        }
};