class Solution {
public:
    
    bool isSubs(string A,string B){
        
        int n = A.size(),m = B.size(); 
        for(int i = 0;i<=n-m;i++){
            int j = 0;
            
            while(j<m && A[i+j]==B[j]) 
            j++;
            
            if(j==m) return true;
        }
        return false;
    }
    
	
    int repeatedStringMatch(string a, string b) {
        
        int n = a.size(),m = b.size();
        int count = 1;
        string temp = a;
        while(a.size()<m){
            a += temp;
            count++;
        }
        if(isSubs(a,b)) return count;
        if(isSubs(a+temp,b)) return count+1;
        return -1;
    }
};