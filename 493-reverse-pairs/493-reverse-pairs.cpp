class Solution {
public:
    int ans=0;
    void merge(vector<int>&a, int l, int m, int r)
    {
        int leftsize= m-l+1;
        int rightsize= r-m;
        
        vector<int>left(leftsize), right(rightsize);
        for(int i=0; i<leftsize; i++){
            left[i]=a[l+i];
        }
            for(int i=0;i<rightsize;i++){
                right[i]=a[m+1+i];
                
            }
        int i,j=0;
            int count=0;
             for(int i=0; i<leftsize; i++){
                 while(j<rightsize and left[i] >(long) 2*right[j]){
                     j++;
                     }
                 count+=j;
                 }
            ans+=count;
            
            i=0; j=0;
            int k=l;
            
            while(i<leftsize  and j< rightsize) {
                if(left[i]>right[j]){
                    a[k++]=right[j++];
                }
                    else{
                        a[k++]=left[i++];
                    }
                }
        while(i<leftsize) {
            a[k++]=left[i++];
        }
        while(j<rightsize){
            a[k++]=right[j++];
        }
    }
                void mergeSort(vector<int>&a, int l,int r){
                if(l<r)
                {
                    int m=(l+r)/2;
                    mergeSort(a,l,m);
                    mergeSort(a,m+1,r);
                    merge(a,l,m,r);
                    
                }
            }
        
    int reversePairs(vector<int>& nums) {
        int n=nums.size()-1;
        mergeSort(nums,0,n);
        return ans;
    }
};