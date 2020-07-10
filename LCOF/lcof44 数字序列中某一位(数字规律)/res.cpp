class Solution {
public:
    int findNthDigit(int n) {
        int i = 1;
        while(n > 0.9*pow(10,i)*i) n -= 0.9*pow(10,i)*i,i++; //大于则前进
        string res = to_string(pow(10, i-1) + (n-1)/i); //求出n所在的数字，并转化位字符串
        return res[(n-1)%i] - '0'; //求出n在第几位，输出。
    }
};