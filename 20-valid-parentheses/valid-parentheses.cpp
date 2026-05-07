class Solution {
public:
    bool isValid(string s) {

        stack<char>st;

        int n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            } 
            if (s[i] == ')' || s[i] == '}' || s[i] == ']'){
                if(st.empty()){
                    return false;
                } else if(s[i] == ')' && st.top() != '('){
                    return false;
                } else if(s[i] == '}' && st.top()!= '{'){
                    return false;
                } else if(s[i] == ']' && st.top() != '['){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};