class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> A,B;
    MinStack() {

    }
    
    void push(int x) {
        A.push(x);
        if(B.empty() || B.top() >= x){
            B.push(x);
        }
    }
    
    void pop() {
        if(A.top() == B.top()){
            B.pop();
        }
        A.pop();
    }
    
    int top() {
        return A.top();
    }
    
    int min() {
        return B.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */