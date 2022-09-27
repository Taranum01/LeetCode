class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        
        int c=(points[0][0]*points[1][1]- points[1][0]*points[0][1]); //x1y2-x2y1=c
        int Y=points[0][1]-points[1][1]; //y1-y2
        int X=points[0][0]-points[1][0]; //x1-x2
        
        if(points[2][1]*X==(points[2][0]*Y)+c) //y=mx+c, m=y/x
            return false;
        else 
            return true;
    
    }
};