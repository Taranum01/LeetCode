
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(),l=0,r=0,ans=0;     
        
        vector<int> count(256,0);      
        
        while(r<n)      
        {
            count[s[r]]++;     
            
            while(count[s[r]]>1)      // the char is repeated
            {
                count[s[l]]--;     //reduce the occurence of char 
                
                l++;       //contraction of the present window 
            }
            ans=max(ans,r-l+1);    
            
            r++;     
        }
        return ans;
    }
};

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
        
//         vector<int> mp(256, -1); 
        
//         int left=0;
//         int right=0;
//         int n= s.size();
//         int len=0;
        
//         while(right<n){
//             if(mp[s[right]!= -1])
//             left= max(mp[s[right]]+1,left);
//             mp[s[right]]=right;
//             len= max(len, right-left + 1);
//             right++;
//     }
//     return len;
//     }
// };

