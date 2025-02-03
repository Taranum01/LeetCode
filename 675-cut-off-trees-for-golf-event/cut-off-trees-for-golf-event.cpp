class Solution {
private:
    const int MAX_D = 1061109567;
public:

    int cutOffTree(vector<vector<int>>& forest) {

        int rows = forest.size();
        int cols = forest[0].size();

        int totalDist = 0;

        set<pair<int, pair<int, int>>> treePos;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (forest[r][c] > 1) {
                    treePos.insert({forest[r][c], {r, c}});
                }
            }
        }

        int startX = 0, startY = 0;

        for (auto& tree : treePos) {

            int targetX = tree.second.first;
            int targetY = tree.second.second;

            int distanceToNextTree = bfs(forest, rows, cols, startX, startY, targetX, targetY);

            if (distanceToNextTree == -1) return -1;

            totalDist += distanceToNextTree;

            forest[targetX][targetY] = 1;
            startX = targetX;
            startY = targetY;
        }

        return totalDist;
    }

    int bfs(vector<vector<int>>& forest, int rows, int cols, int startX, int startY, int targetX, int targetY) {

        int distance[rows + 2][cols + 2];

        memset(distance, 0x3f, sizeof(distance));

        int dX[] = {1, 0, -1, 0};
        int dY[] = {0, 1, 0, -1};

        queue<pair<int, int>> q;
        q.push({startX, startY});
        distance[startX][startY] = 0;

        while (!q.empty()) {
            pair<int, int> currentPos = q.front();
            q.pop();

            if (currentPos.first == targetX && currentPos.second == targetY) {
                return distance[targetX][targetY];
            }

            for (int dir = 0; dir < 4; dir++) {

                int newX = currentPos.first + dX[dir];
                int newY = currentPos.second + dY[dir];

                if (newX < 0 || newX >= rows || newY < 0 || newY >= cols) continue;
                if (forest[newX][newY] == 0) continue;
                if (distance[newX][newY] != MAX_D) continue;

                distance[newX][newY] = distance[currentPos.first][currentPos.second] + 1;
                q.push({newX, newY});
            }
        }

        return -1;
    }
};
