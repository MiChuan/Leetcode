class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.empty() || popped.empty()) return true;
        stack<int> pu;
        int i = 0;
        for(int num : pushed) {
            pu.push(num); // num 入栈
            while(!pu.empty() && pu.top() == popped[i]) { // 循环判断与出栈
                pu.pop();
                i++;
            }
        }
        return pu.empty();
    }
};