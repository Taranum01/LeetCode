class Solution {
public:
    string answerString(string word, int numFriends) {

        int n = word.length();

        if( numFriends == 1)
            return word;

        string res;

        int longestPossible = n - (numFriends - 1);

        for(int i = 0; i < n; i++) {
            int canTakeLength = min(longestPossible, n-i);

            res = max(res, word.substr(i, canTakeLength));
        }

        return res;
    }
};