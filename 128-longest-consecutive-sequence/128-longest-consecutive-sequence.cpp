class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>hashSet;
        for(int num:nums)
        {
            hashSet.insert(num);
        }
        int longestSeq=0;
        for(int num:nums){
            if(!hashSet.count(num-1))
            {
                int currNum= num;
                int currSeq= 1;
            
            while(hashSet.count(currNum+1)){
                currNum+=1;
                currSeq+=1;
            }
            
            longestSeq= max(longestSeq, currSeq);
        }
        
    }
    return longestSeq;
    }
};