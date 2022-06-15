void dfs(vector<vector<char>>& board, int i, int j)
{
    if(board[i][j] == 'O'){
        
        board[i][j] = '1';

        if(i+1 < board.size()) dfs(board, i+1, j);
        if(i > 1) dfs(board, i-1, j);
        if(j+1 < board[i].size()) dfs(board, i, j+1);
        if(j > 1) dfs(board, i, j-1);
    }
}
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0)
            return;
        int row = board.size(), col = board[0].size();
        
        //first row and last row
        for(int i=0; i<row; i++){
            dfs(board, i, 0);
            dfs(board, i, col-1);
        }
        //first col and last col
        for(int j=1; j<col-1; j++){
            dfs(board, 0, j);
            dfs(board, row-1, j);
        }
        
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '1') board[i][j] = 'O';
    }
};