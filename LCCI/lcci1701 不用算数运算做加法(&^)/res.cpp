class Solution {
public:
    int add(int a, int b) {
        unsigned int a1 = a, b1 = b;
        while(b1 != 0) { // 当进位为 0 时跳出
            unsigned int c = (a1 & b1) << 1;  // c = 进位
            a1 ^= b1; // a = 非进位和
            b1 = c; // b = 进位
        }
        return a1;
    }
};