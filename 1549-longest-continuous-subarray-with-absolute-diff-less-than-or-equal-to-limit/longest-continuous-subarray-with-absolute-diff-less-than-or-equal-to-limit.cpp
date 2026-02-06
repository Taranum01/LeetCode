class Solution {
public:
	int longestSubarray(vector<int>& nums, int limit)
	{
		int ans = 0;

		deque<int> minQ;
		deque<int> maxQ;

		int start = 0,end = 0;

		while (end < nums.size()) 
		{
			int x = nums[end];
\
			while (!minQ.empty() && nums[minQ.back()] >= x) 
            minQ.pop_back();
			minQ.push_back(end);

			while (!maxQ.empty() && nums[maxQ.back()] <=x ) 
            maxQ.pop_back();
			maxQ.push_back(end);

			int mini = nums[minQ.front()];
			int maxi = nums[maxQ.front()];

			if (maxi-mini > limit) 
			{
				start++;

				if (start > minQ.front()) minQ.pop_front();
				if (start > maxQ.front()) maxQ.pop_front();
			} 
			else
			{
				ans = max(ans,end-start+1);
				end++;
			}
		}
		return ans;
	}
};