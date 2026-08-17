class MedianFinder {
public:
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
    int count;
    MedianFinder() {
        count = 0;
    }
    
    void addNum(int num) {
        //put the element in correct heap
        if(maxH.empty() || num <= maxH.top())
            maxH.push(num);
        else
            minH.push(num);

        //now rebalance
        if(minH.size() + 1 < maxH.size()){
            minH.push(maxH.top());
            maxH.pop();
        }else if(minH.size() > maxH.size()){
            maxH.push(minH.top());
            minH.pop();
        }
        
        count++;
    }
    
    double findMedian() {
        //int n = count/2;
        /*while(n){
            int a = minH.top();
            minH.pop();
            maxH.push(a);
            n--;
        }*/
        if(count % 2 != 0) return maxH.top();
        return ((double)minH.top() + (double)maxH.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */