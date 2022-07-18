class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int a=0; int b=0;
        for(int S: A)
            a+=S;
        for(int S: B)
            b+=S;
        
        vector<int>ans;
        int n= A.size(), m=B.size();
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int diff= A[i]-B[j];
                if(a-diff == b+diff){
                    ans.push_back(A[i]);
                    ans.push_back(B[j]);
                    return ans;
                }
            }
        }
        
         return ans;
    }
};