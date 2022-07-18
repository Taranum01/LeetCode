class Solution {
public:
    string reverseStr(string s, int k) {
       
        int start= 0;
        int end= min(k, (int)s.length());
            while(start<s.length()){
                reverse(s.begin()+start, s.begin()+end);
                start+=2*k;
                end= min(start+k, (int)s.length());
            }
        return s;
    }
};