class Solution {
public:
    int fib(int n) {
        int mod = 1000000007;
        vector<int> fib(n + 1 + 1);
        fib[1] = 1;
        for(int i = 2; i <= n; i++) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
        return fib[n];
    }
};