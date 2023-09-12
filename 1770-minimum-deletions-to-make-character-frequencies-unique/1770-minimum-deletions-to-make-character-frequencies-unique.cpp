class Solution {
public:
    
    int minDeletions(string s) {
        
        vector<int> v(26); 
        
        for(auto ele : s){ 
            v[ele - 'a']++; 
        }
        
        sort(v.begin(),v.end(), greater<int>());
        
        int max_f = v[0];
        int ans=0;
        
        for(auto freq : v) {
            if(freq > max_f)
            {
                if(max_f>0)
                    ans+=(freq-max_f); 
                else
                    ans+=freq;
            }
            max_f=min(max_f-1,freq-1); 
        }
        return ans;
    }
};