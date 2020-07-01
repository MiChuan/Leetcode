class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;//底数为0
        long b = n;//记录二进制位
        double res = 1.0;
        if(b < 0) {//幂指数为负数
            x = 1 / x;
            b = -b;
        }
        while(b > 0) {//遍历幂指数二进制位
            if((b & 1) == 1) res *= x;//各二进制位指数运算结果相乘
            x *= x;//计算各二进制位指数基
            b >>= 1;
        }
        return res;
    }
};