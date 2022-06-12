class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.length()<1) 
        return "";
        int n= s.length();
        bool table[n][n];
        for(int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
                table[i][j]=false;
        }
        int max_len=1;
        int start=0;
        for(int i=0;i<n;i++)
        {
            table[i][i]=true;
        }
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
            start=i;
            max_len=2;
            table[i][i+1]=true;
            }
        }
        for(int k=3;k<=n;k++)
        {
            for(int i=0; i<n-k+1;i++)
            {
            int j=i+k-1;
            if(table[i+1][j-1] && s[i]==s[j])
                
            {
                table[i][j]=true;
                if(k>max_len)
                {
                    max_len=k;
                    start=i;
                }
            }
        }
    }
         string res="";
        for(int i=start; i<=start+max_len-1;i++)
        {
            res =res+s[i];
        }
        return res;
    }
    
};
