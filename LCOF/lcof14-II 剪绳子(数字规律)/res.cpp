class Solution {
public:
    int cuttingRope(int n) {
        if(n<=3) return n-1;
        int b = n % 3;
        int mod = 1000000007;
        long ans = 1, x = 3;
        for(int a=n/3-1;a>0;a/=2){
            if(a%2==1) ans = (ans * x) % mod;
            x = (x * x) % mod; 
        }
        return int(ans* (12/(4 - b % 3)) % mod);
    }
};