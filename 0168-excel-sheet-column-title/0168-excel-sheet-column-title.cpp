class Solution {
public:
   string convertToTitle(int n) {
        string s;
        while(n) {
            n--;
            int pop = n % 26;
            n = n / 26;
            s.push_back(pop + 'A');
        }
        reverse(s.begin(), s.end());
        return s;
        
    }
};