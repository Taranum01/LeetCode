class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        if(num1.length()>num2.length()){
            swap(num1,num2);
        }
        while(num1.length()<num2.length()){
            num1+="0";
        }
        string ans = "";
        int carry = 0;
        for(int i=0;i<num1.length();i++){
            int value = (num1[i] - '0') + (num2[i] - '0') + carry;
            int curr = value%10;
            carry = value/10;
            ans+=('0'+curr);
        }
        if(carry)
            ans+=('0'+carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};