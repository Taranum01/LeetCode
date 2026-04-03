class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        sort(time.begin(),time.end());
        
        int n = time.size();
        long long low = 0;
        long long high = 1LL*time[n-1]*totalTrips;
        long long ans = 1LL*time[n-1]*totalTrips;

        while(low<high){

            long long mid = low+(high-low)/2;
            long long timetaken = 0;

            for(int i=0; i<time.size(); i++){
                timetaken += (mid/time[i]);
            }

            if(timetaken >= totalTrips){
                ans = min(ans,mid);
                high = mid;
            }
            else {
                low=mid+1;
            }
        }
        return ans;
    }
};