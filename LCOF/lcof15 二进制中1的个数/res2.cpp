class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n != 0){
            ++res;
            n &= n-1;//每次去掉最右边的1
        }
        return res;
    }
};