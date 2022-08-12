class Solution {
public:
    
    bool check(vector<int>&piles, int mid, int h) {
        
    int time = 0;
    for (int i=0; i<piles.size(); i++) {

        if (piles[i]%mid != 0) {
            // in case of odd number
            time +=((piles[i] / mid) + 1);
        }
        else {
            // in case of even number
            time += (piles[i] / mid);
        }
    }
        
    if (time <= h) {
        return true;
    }
    else {
        return false;
    }
}
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int start=1;
        int end= *max_element(piles.begin(), piles.end());
        
        while(start<end)
        {
            int mid= start+ (end-start)/2;
            if((check(piles, mid, h)==true)){
                end=mid;
            }
            else {
                start=mid+1;
            }
        }
           return end; 
    }
};

