class Solution {
public:

    int n;
    
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

    bool check(vector<vector<int>>& distNearestThief, int sf) {

        queue<pair<int, int>> q;

        vector<vector<bool>> visited(n, vector<bool>(n, false));
       
        q.push({0, 0});
        visited[0][0] = true;

        if(distNearestThief[0][0] < sf)
            return false;

        while(!q.empty()) {
            int curr_i = q.front().first;
            int curr_j = q.front().second;

            q.pop();

            if(curr_i == n-1 && curr_j == n-1) {
                return true;
            }

            for(vector<int>& dir : directions) {
                int new_i = curr_i + dir[0];
                int new_j = curr_j + dir[1];
                if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < n && visited[new_i][new_j] != true) {
                    if(distNearestThief[new_i][new_j] < sf) {
                        continue; 
                    }
                    q.push({new_i, new_j});
                    visited[new_i][new_j] = true;
                }

            }
        }

        return false;
        
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        n = grid.size();

        vector<vector<int>> distNearestThief(n, vector<int>(n, -1));
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }

        int level = 0;
        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                int curr_i = q.front().first;
                int curr_j = q.front().second;
                q.pop();
                distNearestThief[curr_i][curr_j] = level;
                for(vector<int>& dir : directions) {
                    int new_i = curr_i + dir[0];
                    int new_j = curr_j + dir[1];

                    if(new_i < 0 || new_i >= n || new_j < 0 || new_j >= n || visited[new_i][new_j]) {
                        continue;
                    }

                    q.push({new_i, new_j});
                    visited[new_i][new_j] = true;

                }

            }
            level++;
        }

        int l = 0;
        int r = 400;
        int res = 0;

        while(l <= r) {
            int mid_sf = l + (r-l)/2;

            if(check(distNearestThief, mid_sf)) {
                res = mid_sf;
                l = mid_sf+1;
            } else {
                r = mid_sf-1;
            }
        }

        return res;
        
    }
};
