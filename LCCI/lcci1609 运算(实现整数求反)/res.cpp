class Operations {
private:
    vector<int> pos, neg;
    int getNeg(int a){                  // 求反
        if(a == 0)
            return 0;
        int result = 0;
        if(a > 0){
            for(auto p = neg.rbegin(); p != neg.rend(); p++){
                if(*p + a < 0)          // 找到第一个负数，使得求和大于 0；
                    continue;
                a += *p;                // 加上该负数后，成为新的需要计算的正数
                result += *p;
            }
        }
        else{
            for(auto p = pos.rbegin(); p != pos.rend(); p++){
                if(*p + a > 0)
                    continue;
                a += *p;
                result += *p;
            }
        }
        return result;
    }
public:
    Operations() {
        int p = 1, q = -1;                  
        pos.push_back(p);  
        neg.push_back(q); 
        for(int i = 1; i < 31; i++){
            p += p;
            q += q;
            pos.push_back(p);               // 将 2 的正数幂放入队列
            neg.push_back(q);               // 将 2 的负数幂放入队列
        }
    }
    
    int minus(int a, int b) {
        return a + getNeg(b);
    }
    
    int multiply(int a, int b) {        // 多少次 a 的求和
        if(a == 0 || b == 0)
            return 0;
        if(a == 1)
            return b;
        if(b < 0)                       // 只要求 b 为正数，是因为待会要用 b 作为 a 的快速乘迭代条件，使用正数队列来做；
            return getNeg(multiply(a, getNeg(b)));
        
        int result = a;
        int times = 1;
        while(times < pos[30] && times + times <= b){    // 累加到小于b里最大的次数
            result += result;
            times += times;
        }
        result += multiply(a, minus(b, times));       // 累加剩下的次数（b-times）
        return result;
    }
    
    int divide(int a, int b) {          // 在 a 里面包含多少个 b
        if(a == 0)
            return 0;
        int result = 1;
        if(a > 0){                      // 只需要写同号的情况
            if(b == INT_MIN)            // 防止下一句溢出
                return 0;
            if(b < 0)
                return getNeg(divide(a, getNeg(b)));
            if(a < b)
                return 0;
            int times = b;
            while(times < pos[30] && times + times <= a){
                result += result;
                times += times;
            }
            result += divide(minus(a, times), b);         // 累加剩下的 a 能包含多少个 b
        }
        else{
            if(b == 1)
                return a;                                   // 防止 a 为 INT_MIN时，下一句溢出
            if(b > 0)
                return getNeg(divide(a, getNeg(b)));
            if(a > b)
                return 0;
            int times = b;
            while(times >= neg[30] && times + times >= a){
                result += result;
                times += times;
            }
            result += divide(minus(a, times), b);
        }
        return result;
    }
};

/**
 * Your Operations object will be instantiated and called as such:
 * Operations* obj = new Operations();
 * int param_1 = obj->minus(a,b);
 * int param_2 = obj->multiply(a,b);
 * int param_3 = obj->divide(a,b);
 */