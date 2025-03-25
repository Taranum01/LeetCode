class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();

        sort(begin(intervals), end(intervals));

        vector<vector<int>> res;

        res.push_back(intervals[0]);

        for(int i = 1; i < n; i++) {
            if(intervals[i][0] < res.back()[1]) { 
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {

        vector<vector<int>> hor;

        vector<vector<int>> vert;

        for(auto &coord : rectangles) {
            int x1 = coord[0];
            int y1 = coord[1];
            int x2 = coord[2];
            int y2 = coord[3];

            hor.push_back({x1, x2});
            vert.push_back({y1, y2});
        }

        vector<vector<int>> res1 = merge(hor);

        if(res1.size() >= 3)
            return true;

        vector<vector<int>> res2 = merge(vert);

        return res2.size() >= 3;
    }
};
