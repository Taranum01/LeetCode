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
                     return count;
                 }
                 else
                 {
                     a--;
                     b++;
                     count+=2;
                 }
             }
             start=a+1;
             end=b-1;
             return count;
             
         }
    
       string longestPalindrome(string s) {
    
          int start=-1;
          int end= -1;
          int len=0;

          int final_start=-1;
          int final_end=-1;

          for(int i=0; i<s.length();i++){
    
          int x= check(s,i,i,start,end);
          if(x>len){
          len=x;
          final_start=start;
          final_end=end;
          }
    
         int y= check(s,i,i+1,start,end);
         if(y>len){
         len=y;
         final_start=start;
         final_end=end;
         }
    
         }
           return s.substr(final_start, final_end-final_start+1);
     }
};

//     string longestPalindrome(string s) {
        
//         if(s.length()<1) 
//         return "";
//         int n= s.length();
//         bool table[n][n];
//         for(int i=0;i<n;i++)
//         {
//             for (int j=0;j<n;j++)
//                 table[i][j]=false;
//         }
//         int max_len=1;
//         int start=0;
//         for(int i=0;i<n;i++)
//         {
//             table[i][i]=true;
//         }
//         for(int i=0;i<n-1;i++)
//         {
//             if(s[i]==s[i+1])
//             {
//             start=i;
//             max_len=2;
//             table[i][i+1]=true;
//             }
//         }
//         for(int k=3;k<=n;k++)
//         {
//             for(int i=0; i<n-k+1;i++)
//             {
//             int j=i+k-1;
//             if(table[i+1][j-1] && s[i]==s[j])
                
//             {
//                 table[i][j]=true;
//                 if(k>max_len)
//                 {
//                     max_len=k;
//                     start=i;
//                 }
//             }
//         }
//     }
//          string res="";
//         for(int i=start; i<=start+max_len-1;i++)
//         {
//             res =res+s[i];
//         }
//         return res;
//     }
    
// };

