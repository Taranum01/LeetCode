class Solution {
public:

    int minTaps(int n, vector<int>& ranges) {

        vector<int> startToEnd(n+1, 0);
        
        for(int i=0; i<ranges.size(); i++) {

            int tapStart = max(0, i - ranges[i]);
            int tapEnd = min(n, i + ranges[i]);
            
            startToEnd[tapStart] = max(startToEnd[tapStart], tapEnd);
        }
        
        int openTaps = 0;
        int currentEnd = 0;
        int maxTapEnd = 0;
        
        for(int i=0; i<n+1; i++) {

            if(i > maxTapEnd)
                return -1;
            
            if(i > currentEnd) {

                openTaps++;
                currentEnd = maxTapEnd;
                
            }
            
            maxTapEnd = max(maxTapEnd, startToEnd[i]);
        }
        
        return openTaps;    
    }
};
