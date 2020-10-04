## [LCOF30 包含min函数的栈](https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/)

### 题目

定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)

### 解析

使用两个栈，一个保存入栈元素，一个非降序栈保存最小元素序列

### 代码

```C++
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> A,B;
    MinStack() {

    }
    
    void push(int x) {
        A.push(x);
        if(B.empty() || B.top() >= x){//B为非降序排序
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
```

