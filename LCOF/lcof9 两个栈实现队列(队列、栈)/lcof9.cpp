class CQueue {
public:
    stack<int> inQueue,outQueue;
    CQueue() {}
    
    void appendTail(int value) {
        inQueue.push(value);
    }
    
    int deleteHead() {
        if(outQueue.empty()&&inQueue.empty()) return -1;
        if(outQueue.empty() && !inQueue.empty()){
            while(!inQueue.empty()){
                outQueue.push(inQueue.top());
                inQueue.pop();
            }
        }
        int tmp = outQueue.top();
        outQueue.pop();
        return tmp;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */