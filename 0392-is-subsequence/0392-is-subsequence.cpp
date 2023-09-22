class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int a = s.length(), b=t.length();
        int j = 0; 
    
    for (int i = 0; i < b and j < a; i++)
        if (s[j] == t[i])
            j++;
 
    return (j == a);
    }
};