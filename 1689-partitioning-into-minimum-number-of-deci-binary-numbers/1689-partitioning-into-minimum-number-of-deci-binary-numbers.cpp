class Solution {
public:
    int minPartitions(string n) {
        
        int ans=0;
        for(char x: n){
            int curr= x-48;
            ans=max(ans,curr);
            
        }
        return ans;
    }
};