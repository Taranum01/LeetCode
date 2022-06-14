class Solution {
public:
    
	int snakesAndLadders(vector<vector<int>>& board) {
		
		int n = board.size();
        int target= n*n;
        
		int moves= 0;
		
		unordered_set<int> visited;
		
		queue<int> q;

		q.push(1);
		visited.insert(1);

		while (!q.empty()) {
			int lsize = q.size();
			
			for (int i = 0; i < lsize; i++) {
				// pop current position
				int curr = q.front();
				q.pop();

				// roll the dice
				for (int dice = 1; dice <= 6; dice++) {
				    // next position 
					int next = curr + dice;

					// row and column number of that position
					int row = (n-1)-(next - 1) / n;
					int col = (next - 1) % n;

					// flip the row
					// when encounter odd row number
                    
					if ((n-1-row) % 2 != 0) {
						col = n - 1 - col;
					}

					// if encounter a snake or ladder at next
					if (board[row][col] != -1) {
						next = board[row][col];
					}

					if (next == target) {
						return moves+1;
					}

					// if next not visited push in queue 
					if (visited.count(next) == 0) {
						visited.insert(next);
						q.push(next);
					}
				}
			}
			moves++;
		}
		return -1;
	}
};