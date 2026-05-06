class Solution {
public:

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> medians;
        unordered_map<int, int> hashT;

        priority_queue<int> lo;
        priority_queue<int, vector<int>, greater<int>> hi;

        int i = 0;

        while (i < k) {
            lo.push(nums[i++]);
        }

        for (int j = 0; j < k / 2; ++j) {
            hi.push(lo.top());
            lo.pop();
        }

        while (true) {

            if (k & 1) {
                medians.push_back(lo.top());
            } else {
                medians.push_back(
                    ((double)lo.top() + (double)hi.top()) * 0.5
                );
            }

            if (i >= nums.size())
                break;

            int outNum = nums[i - k];
            int inNum = nums[i++];

            int balance = 0;

            if (outNum <= lo.top()) {
                balance--;
            } else {
                balance++;
            }

            hashT[outNum]++;

            if (!lo.empty() && inNum <= lo.top()) {
                balance++;
                lo.push(inNum);
            } else {
                balance--;
                hi.push(inNum);
            }

            if (balance < 0) {
                lo.push(hi.top());
                hi.pop();
            }

            if (balance > 0) {
                hi.push(lo.top());
                lo.pop();
            }

            while (!lo.empty() && hashT[lo.top()]) {
                hashT[lo.top()]--;
                lo.pop();
            }

            while (!hi.empty() && hashT[hi.top()]) {
                hashT[hi.top()]--;
                hi.pop();
            }
        }

        return medians;
    }
};