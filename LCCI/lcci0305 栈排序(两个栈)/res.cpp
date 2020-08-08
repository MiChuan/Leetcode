class SortedStack {
public:
    stack<int>s1;//原栈为降序
    stack<int>s2;//辅助栈为升序
    SortedStack() {

    }
    
    void push(int val) {
        while(!s2.empty() && s2.top() > val){//辅助栈中存在比val大的值
            s1.push(s2.top());
            s2.pop();
        }
        while(!s1.empty() && s1.top() < val){//原栈中有比val小的值
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
    }
    
    void pop() {
        while(!s2.empty()){//清空辅助栈
            s1.push(s2.top());
            s2.pop();
        }
        if(!s1.empty()) s1.pop();
    }
    
    int peek() {
        while(!s2.empty()){//清空辅助栈
            s1.push(s2.top());
            s2.pop();
        }
        if(!s1.empty()) return s1.top();
        else return -1;
    }
    
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }
};