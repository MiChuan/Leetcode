class Solution {
public:
    int convertInteger(int A, int B) {
        uint32_t N = A ^ B;
        int res = 0;
        while(N!=0){
            ++res;
            N &= N-1;
        }
        return res;
    }
};