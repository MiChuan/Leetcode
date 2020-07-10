class Solution {
public:
    int cuttingRope(int n) {
        if(n <= 3) return n - 1;//段长不大于3
        int con = n / 3, rem = n % 3;//求段长为3时的段数、剩余段长
        if(rem == 0) return pow(3, con);//等分为段长3的con段
        if(rem == 1) return pow(3, con - 1) * 4;//剩余段长为1，加到一个段长3上
        return pow(3, con) * 2;//剩余段长2，单独成段
    }
};