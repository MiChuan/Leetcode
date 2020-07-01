class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n-1)) == 0;//n&(n-1)消掉最右边的1
    }
};