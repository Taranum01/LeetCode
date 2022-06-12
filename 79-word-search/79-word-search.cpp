class Solution {
public:
    bool dfs(vector<vector<char>>&board,int i, int j, vector<vector<bool>> &visited, int count,string word)
    {
        if(count==word.size())
            return true;
       
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || visited[i][j]== true ||
          board[i][j]!=word[count])
        
            return false;
        visited[i][j]=true;
        bool result= dfs (board,i-1, j, visited, count+1, word) ||
            dfs (board,i+1, j, visited, count+1, word) ||
            dfs (board,i, j-1, visited, count+1, word) ||
            dfs (board,i, j+1, visited, count+1, word);
        
        visited[i][j]=false;
        return result;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n;j++)
            {
                if (word[0]==board[i][j] && dfs (board,i, j, visited, 0, word))
                {
                    return true;
                }
            }
        }
         return false;
    }
};