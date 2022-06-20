class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        
        set<string>s1(words.begin(),words.end());
        set<string>s2(words.begin(),words.end());
        
        for(auto part:s1){
            for(int i=1;i<part.size();i++){
                s2.erase(part.substr(i));
            }
        }
        int sum=0;
        for(auto part:s2){
            sum+=part.size()+1;
        }
            return sum;
        }
    
};