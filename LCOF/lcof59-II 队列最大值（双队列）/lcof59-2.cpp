class MaxQueue {
	int queue[10001];
    int mymax = -1;
    int begin = 0, end = 0;
public:
  
    MaxQueue() {
    }
    
    int max_value() {
		if(begin == end) mymax = -1;
        return mymax;
    }
    
    void push_back(int value) {
        end = (++end)%10001;
		queue[end] = value;
        if(value > mymax) mymax = value;
        else{
            for (int i = (begin+1)%10001; i <= (end+1)%10001; i=(i+1)%10001)
                mymax = max(mymax, queue[i]);
        }
    }
    
    int pop_front() {
        if(begin == end){
            return -1;
        }
        int pop;
		begin = (begin+1)%10001;
        pop = queue[begin];
        return pop;
    }
};

/**
 * Your mymaxQueue object will be instantiated and called as such:
 * mymaxQueue* obj = new mymaxQueue();
 * int param_1 = obj->mymax_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */