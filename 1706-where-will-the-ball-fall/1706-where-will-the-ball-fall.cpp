class Solution {
public:
    
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();        
        vector<int> ans(m);
        
        for(int i=0;i<m;i++)
        {
            int curr_row=0;
            int curr_col=i;
            
            while(curr_row<n)
            {
                // ball slide iff the adjacent right grid cell is same as current grid cell
                if(grid[curr_row][curr_col]==1 && curr_col+1<m && grid[curr_row][curr_col+1]==1)
                {
                    //move to down and right direction
                    curr_row++;
                    curr_col++;
                }
                // ball slide iff the adjacent left grid cell is same as current grid cell
                else if(grid[curr_row][curr_col]==-1 && curr_col-1>=0 && grid[curr_row][curr_col-1]==-1)
                {
                    //move to down and left direction
                    curr_row++;
                    curr_col--;
                }
                // found a v shaped  board or a wall
                else
                    break;
            }
            
            if(curr_row==n)
                ans[i]=curr_col;
        
            else
                ans[i]=-1;
        }
        return ans;       
    }
};