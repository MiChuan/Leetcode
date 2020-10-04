## [LCOF09 用两个栈实现队列](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)

### 题目

用两个栈实现一个队列。完成push_back, pop_front, front, empty操作

### 解析

- 使用两个栈，一个入栈inS，一个出栈outS
- 元素入队压入inS栈，出队压入outS栈

### 代码

```C++
class MyQueue {
public:
    stack<int> inS,outS;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        inS.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp = peek();
        outS.pop();
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        if(outS.empty()){
            while(!inS.empty()){
                outS.push(inS.top());
                inS.pop();
            }
        }
        return outS.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return inS.empty() && outS.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```

