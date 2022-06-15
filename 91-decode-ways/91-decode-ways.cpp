class Solution {
public:
    int numDecodings(string s) {
        if(s.length()==0 or s[0] == '0') return 0;
        if(s.length()==1) return 1;
        
        int count1=1, count2=1;
        for(int i=1; i<s.length(); i++){
        int a= s[i]-'0';
        int aa= (s[i-1]-'0') *10+ a;
        int count =0;
        if(a>0) count+=count2;
        if(aa>=10 && aa<=26) count+=count1;
        count1=count2;
        count2=count;
        
    }
    return count2;
}
};