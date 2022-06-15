class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        
            int row_start=0;
            int row_end=n-1;
            int col_start=0;
            int col_end=n-1;
            int counter=1;
        
        while(row_start<=row_end && col_start<=col_end)
        {
            for(int i=col_start; i<=col_end; i++)
            {
                ans[row_start][i]=counter++;
    }
            row_start++;
        for(int i=row_start; i<=row_end; i++)
            {
                ans[i][col_end]=counter++;
    }
            col_end--;
        
        if(row_start<=row_end){
            for(int i=col_end; i>=col_start; i--){
                
                ans[row_end][i]=counter++;
            }
        row_end--;
        }
        
        if(col_start<=col_end){
            for(int i=row_end; i>=row_start; i--){
                
                ans[i][col_start]=counter++;
            }
        col_start++;
        }

    }
     return ans;
}
};