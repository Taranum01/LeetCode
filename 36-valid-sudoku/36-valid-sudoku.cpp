class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       
        vector<unordered_set<int>> row(9);
        vector<unordered_set<int>> col(9);
        map<pair<int,int>,unordered_set<int>> block;
        
        for(int r=0;r<9;r++)
        {
            for(int c=0;c<9;c++)
            {
                if(board[r][c]=='.')
                    continue;
                
                int currdigit=board[r][c]-48;
                if(row[r].find(currdigit)!=row[r].end() ||
                   col[c].find(currdigit)!=col[c].end() ||
                   block[{r/3,c/3}].find(currdigit)!=block[{r/3,c/3}].end())
                {
                    return false;
                }
                
                row[r].insert(currdigit);
                col[c].insert(currdigit);
                block[{r/3,c/3}].insert(currdigit);
            }
        }
        return true;
    }
};