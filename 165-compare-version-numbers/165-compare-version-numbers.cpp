class Solution {
public:
    int compareVersion(string v1, string v2) {
        
        int i=0; 
        int j=0; 
        int v1_len= v1.size();
        int v2_len= v2.size();
        int n1; 
        int n2;
        
        while(i<v1_len || j<v2_len){
            n1=0;
            n2=0;
            while(i<v1_len && v1[i]!='.'){
                n1= n1*10+ (v1[i]-'0');
                i++;
            }
            while(j<v2_len && v2[j]!='.'){
                n2= n2*10+ (v2[j]-'0');
                j++;
            }
            
            if(n1<n2) return -1;
            else if(n1>n2) return 1;
            i++;
            j++;
        }
        return 0;
    }
};