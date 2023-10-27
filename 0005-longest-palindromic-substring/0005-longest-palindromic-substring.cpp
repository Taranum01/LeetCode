class Solution {
public:
    
         int check(string s, int a, int b, int &start, int &end){
             
             int count=0;
             if(a==b){
                 count++;
                 a--;
                 b++;
             }
             while(a>=0 && b<s.length()){
                 if(s[a]!=s[b]){
                     start=a+1;
                     end=b-1;
                     return count; //not match
                 }
                 else
                 {
                     a--;
                     b++;
                     count+=2;  //2 chars added
                 }
             }
             start=a+1;
             end=b-1;
             return count; //not match
             
         }
    
       string longestPalindrome(string s) {
    
          int start=-1;   //curr start
          int end= -1;    //curr end
          int len=0;

          int final_start=-1;   //longest subs start
          int final_end=-1;

          for(int i=0; i<s.length();i++){
    
          int x= check(s,i,i,start,end); //longest odd len
          if(x>len){
          len=x;
          final_start=start;
          final_end=end;
          }
    
         int y= check(s,i,i+1,start,end); // longest even len
         if(y>len){
         len=y;
         final_start=start;
         final_end=end;
         }
    
         }
           return s.substr(final_start, final_end-final_start+1);
     }
};

