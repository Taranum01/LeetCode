class Solution {
public:
    int romanToInt(string str) {

       map<int,int>roman;

       roman.insert(make_pair('I',1));
       roman.insert(make_pair('V',5));
       roman.insert(make_pair('X',10));
       roman.insert(make_pair('L',50));
       roman.insert(make_pair('C',100));
       roman.insert(make_pair('D',500));
       roman.insert(make_pair('M',1000));


       int len = str.length();
       int num , sum = 0;

       for(int i = 0; i < len;){
           if(i == (len-1) || (roman[str[i]] >= roman[str[i+1]])){
               num = roman[str[i]];
               i++;
           } else {
               num = roman[str[i+1]] - roman[str[i]];
               i += 2;
           }
           sum = sum + num;
       }

       return sum;
    }
};