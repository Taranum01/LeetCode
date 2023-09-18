class Solution {
public:
    
    typedef pair<int, int> P;
    
    int binarySearch(vector<int>& arr, int l, int r) {

        int mid;
        int res = -1;
        while(l <= r) {
            mid = l + (r-l)/2;
            
            if(arr[mid] == 1) {
                res = mid;
                l = mid+1;
            } else if(arr[mid] == 0) {
                r = mid-1;
            }
            
        }
        return res+1; 
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<P> countOnes; 
    
        for(int row = 0; row < m; row++) {
            
            int num_ones = binarySearch(mat[row], 0, n-1); 
            
            countOnes.push_back({num_ones, row});
        }
        
        sort(begin(countOnes), end(countOnes)); 
        
        vector<int> res(k);
        
        for(int i = 0; i < k; i++) {
            res[i] = countOnes[i].second;
        }
        
        return res;
    }
};