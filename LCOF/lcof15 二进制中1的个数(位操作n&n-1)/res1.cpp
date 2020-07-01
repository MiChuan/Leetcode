class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n != 0){
            res += n & 0x1;
            n >>= 1;//逻辑右移
        }
        return res;
    }
};