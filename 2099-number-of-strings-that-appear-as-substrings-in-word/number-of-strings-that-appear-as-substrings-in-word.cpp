class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        int res = 0;

        for (string str : patterns) {
            if (word.find(str) != string::npos) {
                res++;
            }
        }

        return res;
    }
};