class Solution {
public:
    int countSegments(string s) {
        
        stringstream ss(s);
        int ans=0;
        while(ss>>s){
            
            ans+=1;
        }
        return ans;
    }
};