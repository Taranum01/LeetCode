class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        
        long sum1=0, sum2=0;
        int i=0, j=0, n=nums1.size(), m=nums2.size();
        long res=0;
        
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                sum1+=nums1[i];
                i+=1;
            }
            else if(nums2[j]<nums1[i]){
                sum2+=nums2[j];
                j+=1;
            }
            else {
                res+=max(sum1,sum2)+nums1[i];
                i+=1;
                j+=1;
                sum1=0, sum2=0;
            }
        }
        while(i<n){
            sum1+=nums1[i++];
        }
        while(j<m){
            sum2+=nums2[j++];
        }
        return(max(sum1,sum2)+res)%1000000007;
    }
};