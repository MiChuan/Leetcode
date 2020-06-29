class Solution {
public:
    int numWays(int n) {
        long long mod = 1000000007;
        if(n == 0 || n == 1) return 1;
        long long out[101];
        out[0] = 1, out[1] = 1;
        int i;
        for(i=2;i<=n;i++){
            out[i] = (out[i-1] + out[i-2])% mod;
        }
        return out[n];
    }
  };