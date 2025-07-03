class Solution {
public:
    char kthCharacter(int k) {

        string s = "a";

        while(s.length() < k){

            int l = s.length();
            for(int i=0; i<l; i++){
                char next = 'a' + ((s[i] - 'a' + 1) % 26);
                s += next;
            }

        }
        return s[k-1];
    }
};