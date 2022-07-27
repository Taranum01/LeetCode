class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        
        sort(heaters.begin(), heaters.end());
        int ans=0;
        for( int i=0; i<houses.size(); i++){
            int start=0;
            int end=heaters.size()-1;
            int curr_radius= INT_MAX;
            while(start<=end){
                int mid=start+(end-start)/2;
            if(houses[i]==heaters[mid]){
                curr_radius=0;
            break;
            }
            else {
                int diff=abs(houses[i]-heaters[mid]);
                curr_radius= min(diff, curr_radius);
                if(houses[i]>heaters[mid]){
                    start=mid+1;
                }
                else if(houses[i]<heaters[mid]){
                    end=mid-1;
                }
            }
        }
            ans= max(ans, curr_radius);
    }
        return ans;
    }
};
 