class Solution {
public:
    int calculate(string s) {
        char op = '+';
        int val, res = 0;
        istringstream iss(s);
        stack<int> st;

        while(iss>>val){
            if(op=='+'){//op初始化'+',故第一个数压栈
                st.push(val);
            }else if(op=='-'){
                st.push(-val);
            }else{
                int val2 = st.top(); st.pop();
                if(op=='*') st.push(val*val2);
                else if(op=='/') st.push(val2/val);
            }
            iss>>op;
        }

        while(st.size()){
            res += st.top(); st.pop();
        }
        return res;
    }
};