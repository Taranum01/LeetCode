class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {

        int vert_dist = abs(sy-fy);
        int horz_dist  = abs(sx-fx);
        
        if(vert_dist == 0 && horz_dist == 0 && t == 1) {
            return false;
        }
        
        return t >= max(vert_dist, horz_dist);
        
    }
};