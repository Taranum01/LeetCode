class Solution {
public:
    string smallestSubsequence(string s) {
  
        vector<int>LastIndex(26,0);
        for(int i=0; i<s.length(); i++){
            LastIndex[s[i]-'a']=i;
        }
        
        vector<bool>seen(26,false);
        stack<char>st;
        
        for(int i=0; i<s.size(); i++){
            int curr= s[i]-'a';
            
            if(seen[curr]){
                continue;
            }
        
            while(!st.empty() && st.top()> s[i] && i<LastIndex[st.top()-'a']){
                seen[st.top()-'a']=false;
                st.pop();
            }
            
            st.push(s[i]);
            seen[curr]=true;
        }
        
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};