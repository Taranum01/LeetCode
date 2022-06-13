class MedianFinder {
public:
    
    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() and minHeap.empty())
        {
            maxHeap.push(num);
        }
        else
        {
            if(maxHeap.top() < num)
            {
                minHeap.push(num);
            }
            else
            {
                maxHeap.push(num);
            }
        }
        int a = maxHeap.size();
        int b = minHeap.size();
        
        if(abs(a - b) == 2)
        {
            if(a>b)
            {
                int element = maxHeap.top();
                maxHeap.pop();
                minHeap.push(element);
            }
            else
            {
                int element = minHeap.top();
                minHeap.pop();
                maxHeap.push(element);
            }
        }
    }
    
    double findMedian() {
        int a = maxHeap.size();
        int b = minHeap.size();
        
        if((a + b) % 2 == 0)
        {
            return ((double)maxHeap.top() + (double)minHeap.top())/2.0;  
        }
        else
        {
            if(a>b)
                return maxHeap.top();
            else
                return minHeap.top();
        }
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
