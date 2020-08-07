class StackOfPlates {
    vector<stack<int>> st;
    int cap;
public:
    StackOfPlates(int cap) : cap(cap) {

    }
    
    void push(int val) {
        if (cap <= 0) return;
        if (st.empty() || (*st.rbegin()).size() == cap) {//最后一个栈满
            stack<int> tmp;
            tmp.push(val);
            st.push_back(tmp);
        }
        else {
            (*st.rbegin()).push(val);
        }
    }
    
    int pop() {
        if (st.empty()) {
            return -1;
        }
        else {
            int ret = (*st.rbegin()).top();
            (*st.rbegin()).pop();
            if ((*st.rbegin()).empty()) {//最后一个堆栈空
                st.erase(st.end() - 1);
            }
            return ret;
        }
    }
    
    int popAt(int index) {
        if (index >= st.size()) {
            return -1;
        }
        else {
            int ret = st[index].top();
            st[index].pop();
            if (st[index].empty()) {//指定堆栈空
                st.erase(st.begin() + index);
            }
            return ret;
        }
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */