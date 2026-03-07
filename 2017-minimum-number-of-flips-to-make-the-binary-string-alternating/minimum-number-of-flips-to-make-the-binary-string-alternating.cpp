class Solution {
public:
    int minFlips(string s) {

        int n = s.size();
        s += s;

        string s1, s2;

        for(int i = 0; i < 2*n; i++) {
            s1 += (i % 2 ? '0' : '1');
            s2 += (i % 2 ? '1' : '0');
        }

        int i = 0, j = 0;
        int res1 = 0, res2 = 0;
        int res = INT_MAX;

        while(j < 2*n) {

            if(s[j] != s1[j]) res1++;
            if(s[j] != s2[j]) res2++;

            if(j - i + 1 > n) {
                if(s[i] != s1[i]) res1--;
                if(s[i] != s2[i]) res2--;
                i++;
            }
            if(j - i + 1 == n)
                res = min({res, res1, res2});

            j++;
        }

        return res;
    }
};