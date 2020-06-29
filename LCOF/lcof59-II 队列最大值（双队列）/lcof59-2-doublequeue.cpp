class MaxQueue {
	int queue[20000];
    int sort[20000];
    int qbegin = 0, qend = 0;
    int sbegin = 0, send = 0;
public:
  
    MaxQueue() {
    }
    
    int max_value() {
        if(sbegin==send) return -1;
        return sort[sbegin+1];
    }
    
    void push_back(int value) {
        while(sbegin!=send && sort[send]<value){
            send--;
        }
        sort[++send] = value;
        queue[++qend] = value;
    }
    
    int pop_front() {
        if(qbegin == qend) return -1;
        int qfront = queue[qbegin+1];
        if(qfront == sort[sbegin+1]){
            sbegin++;
        }
        qbegin++;
        return qfront;
    }
};

/**
 * Your mymaxQueue object will be instantiated and called as such:
 * mymaxQueue* obj = new mymaxQueue();
 * int param_1 = obj->mymax_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */