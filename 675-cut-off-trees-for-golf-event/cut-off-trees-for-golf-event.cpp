class Solution {
private:
    const int MAX_DISTANCE = 1061109567;

public:
    int cutOffTree(vector<vector<int>>& forest) {

        int rows = forest.size();
        int cols = forest[0].size();

        int totalDistance = 0;

        set<pair<int, pair<int, int>>> treePositions;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (forest[r][c] > 1) {
                    treePositions.insert({forest[r][c], {r, c}});
                }
            }
        }

        int startX = 0, startY = 0;

        for (auto& tree : treePositions) {
            int targetX = tree.second.first;
            int targetY = tree.second.second;

            int distanceToNextTree = bfs(forest, rows, cols, startX, startY, targetX, targetY);

            if (distanceToNextTree == -1) return -1;

            totalDistance += distanceToNextTree;

            forest[targetX][targetY] = 1;
            startX = targetX;
            startY = targetY;
        }

        return totalDistance;
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
            pair<int, int> currentPosition = q.front();
            q.pop();

            if (currentPosition.first == targetX && currentPosition.second == targetY) {
                return distance[targetX][targetY];
            }

            for (int direction = 0; direction < 4; direction++) {

                int newX = currentPosition.first + dX[direction];
                int newY = currentPosition.second + dY[direction];

                if (newX < 0 || newX >= rows || newY < 0 || newY >= cols) continue;
                if (forest[newX][newY] == 0) continue;
                if (distance[newX][newY] != MAX_DISTANCE) continue;

                distance[newX][newY] = distance[currentPosition.first][currentPosition.second] + 1;
                q.push({newX, newY});
            }
        }

        return -1;
    }
};
