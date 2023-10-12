class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

       int s=0;
       int e=arr.size()-1;
       int ans=-1;

       while(s<e){
           int m= s+(e-s)/2;
           if(arr[m]>arr[m+1]){
               ans=m;
               e=m;
           }
           else {
               ans=m+1;
               s=m+1;
           }
       } 
       return ans;

    }
};