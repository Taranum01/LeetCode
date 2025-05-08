class Solution {
public:

    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    typedef pair<int, pair<int, int>> P;

    int minTimeToReach(vector<vector<int>>& moveTime) {

        int m = moveTime.size();
        int n = moveTime[0].size();

        vector<vector<int>> res(m, vector<int>(n, INT_MAX));

        priority_queue<P, vector<P>, greater<P>> pq; 

        res[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()) { 

            int currTime = pq.top().first;
            auto cell = pq.top().second;

            int i = cell.first;
            int j = cell.second;

            pq.pop();

            if(i == m-1 && j == n-1) {
                return currTime;
            }

            for(auto &dir : directions) {

                int i_ = i + dir[0];
                int j_ = j + dir[1];

                if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n) {
                    
                    int wait = max(moveTime[i_][j_] - currTime, 0);
                    int arrTime = currTime + wait + 1;

                    if(res[i_][j_] > arrTime) {
                        res[i_][j_] = arrTime;
                        pq.push({arrTime, {i_, j_}});
                    }
                    
                }
            }
        }

        return -1;

    }
};