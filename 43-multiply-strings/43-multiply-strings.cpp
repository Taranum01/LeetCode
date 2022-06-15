class Solution {
public:
   
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") 
        return "0";
        string ans="";
        int n=num1.size(),m=num2.size();
        vector<int> res(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                res[i + j + 1] += (num1[i]-'0') * (num2[j]-'0');
                int curr= res[i + j + 1];
                res[i + j] += curr / 10; 
                res[i + j + 1] = curr%10;
            }
        }
        int i = 0;
        while (res[i] == 0) i++;
        while (i < res.size()) 
        ans+=to_string(res[i++]);
        return ans;
    }
};