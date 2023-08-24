class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {

        while(s.length() % k){
            s.push_back(fill);
        }

            vector<string>res;
            int n = s.length();

            for(int i=0; i<n; i+=k){
                res.push_back(s.substr(i, k));
        }
        return res;
    }
};