class Solution {
public:
    
    static bool compare(vector<int> v1, vector<int> v2)
    {
        return v1[1]>v2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int maxUnits = 0, i = 0;
        
        sort(boxTypes.begin(), boxTypes.end(), compare);
        
        while (truckSize>0 && i<boxTypes.size()){
            
            if(boxTypes[i][0] <= truckSize){
                maxUnits += boxTypes[i][0] * boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
    
            else{
                
                int boxesLeft = truckSize;
                truckSize -= boxesLeft; // here truckSize = 0 
                maxUnits += boxesLeft * boxTypes[i][1]; 
            }
            
            i++;
        }
    
        return maxUnits;
    }
};