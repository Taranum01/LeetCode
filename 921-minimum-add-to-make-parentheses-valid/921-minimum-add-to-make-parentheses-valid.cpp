class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char>st;
        
        for(auto &ch: s){
            if(ch=='('){
                st.push('(');
            }
            else 
                if(st.size()>0 && st.top()=='(')
                    st.pop();
            else
            st.push(')');
        }
        
    return st.size();
    }
};