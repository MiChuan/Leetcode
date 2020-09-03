class MedianFinder {
private:
    priority_queue<int,vector<int>,less<int>>downHeap;
    priority_queue<int,vector<int>,greater<int>>upHeap;

public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(downHeap.empty()||downHeap.top()>=num) downHeap.push(num);
        else upHeap.push(num);
        int factor=downHeap.size()-upHeap.size();
        if(factor>1){
            upHeap.push(downHeap.top());
            downHeap.pop();
        }
        if(factor<0){
            downHeap.push(upHeap.top());
            upHeap.pop();
        }
    }
    
    double findMedian() {
        double res=downHeap.top();
        if(downHeap.size()==upHeap.size())
            res=(res+upHeap.top())/2;
        return res;
    }
};